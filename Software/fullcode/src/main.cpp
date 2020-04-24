#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "esp_wpa2.h"
#include <Wire.h>
#include "driver/adc.h"
#include <esp_wifi.h>
#include <esp_bt.h>
#include "_util.h"
#include <PriUint64.h>
#include "time.h"
#include "sensors.h"

#define ccs881_pwr_pin 15
#define audio_pwr_pin 16
#define amg_pwr_pin 17

// data stored in RTC memory when entering deepsleep
RTC_DATA_ATTR int bootCount = 0; 
RTC_DATA_ATTR bool sensorsinit = false;
RTC_DATA_ATTR static volatile APP_State_t appState = NTPSYNC;
RTC_DATA_ATTR int days_since_sync = 0;

// for sensor data
float audio_voltage = 0;
float pixeltemperature[64];
float tempAMG = 0;
uint16_t data_CCS811[2];





void setup() {
  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  esp_wifi_init(&cfg);

// for enterprise wifi
/*  
  WiFi.mode(WIFI_STA); //init wifi mode
  esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide identity
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide username --> identity and username is same
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD)); //provide password
  esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT(); //set config settings to default
  esp_wifi_sta_wpa2_ent_enable(&config); //set config settings to enable function */

  // disable wifi, bluetooth and adc
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  btStop();
  adc_power_off();
  esp_wifi_stop();
  esp_bt_controller_disable();
  delay( 1 ); // has to be here!

  //start serial monitor
  Serial.begin(115200);

  //Print the wakeup reason for ESP32
	print_wakeup_reason();

  // enable gpio pins
  pinMode(ccs881_pwr_pin,OUTPUT);
  pinMode(audio_pwr_pin,OUTPUT);
  pinMode(amg_pwr_pin, OUTPUT);

  //
  Wire.begin();

  //init sensors
  if(!sensorsinit){
    //init_sensors();
    sensorsinit = true;
  }
}


void loop() {

  switch (appState)
  {

  case WAKESENSORS:{
    wake_sensors();
    appState = READSENSORS;
    goToDeepSleep_ms(105);// sleep until sensors are ready
  }break;

  case READSENSORS:{
    
    // read audio level
    int audio = 0;
    get_audio_level(&audio);
    audio_voltage = (3.3 * audio) / 4095;

    // read AMG sensor data
    get_measurements_AMG8833(pixeltemperature,&tempAMG);

    // read CCSS811 sensor data
    get_measurements_CCS811(data_CCS811);

    // print sensor data
    Serial.print("audio voltage: ");
    Serial.println(audio_voltage);

    Serial.println("AMG pixels: ");
    for(int i=0; i<64; i++){
      Serial.print(pixeltemperature[i]);
      Serial.print(" : ");
    }
    Serial.println(" ");

    Serial.print(" AMG temp: ");
    Serial.println(tempAMG);

    Serial.print("CO2: ");
    Serial.println(data_CCS811[0]);
    Serial.print("TVOC: ");
    Serial.println(data_CCS811[1]);


    //todo determine when to send the data
    // for now: always send the data

    // set next appstate 
    appState = CHECKTIME; 
    
/*     // for testing the sensors:
    // go to deepsleep for 10 seconds, then read the sensors again
    appState = WAKESENSORS;
    goToDeepSleep(10); */

  }break;

  case SENDDATA:{
    appState = SLEEP;// set next appstate

    // create dummy data
    for(int i=0; i<64;i++){
      pixeltemperature[i] = i+20.25;
    }
    tempAMG = 21.55;
    audio_voltage = 0.84;
    data_CCS811[0] = 33;
    data_CCS811[1] = 44;

    int length = sizeof(pixeltemperature);
    int ctr = 0;
    while(true){  
      if(sendMessage(pixeltemperature, tempAMG, audio_voltage, data_CCS811, length)){
        break;
      }
      ctr++;
      if(ctr>3){// timeout after 3 tries
        Serial.print("Data transmission failed!");
        break;
      }
    }
  } break;
   
  case SLEEP:{
    appState = WAKESENSORS;
    //todo
    // change time to 10 minutes instead of seconds
    goToDeepSleep(10);
  }break;

  case CHECKTIME:{
    appState = SENDDATA;

    Serial.println("IN CHECK time");
    printLocalTime();

    // check if the system can be disabled during the night
    int hour = checkhour();
    if(hour == -1){ // if time is not availibly perform a sync
      Serial.println("ERROR: failed to obtain time");
      appState = NTPSYNC;
    }else{
      if(hour > 16 || hour < 9){
        appState = NIGHTSLEEP;
      }
    }

    // check if the local clock has to be synchronised
  }break;
  
  case NTPSYNC:{
    Serial.println("IN SYNC");
     ntp_sync();
     appState = WAKESENSORS;
     goToDeepSleep(10);
  }break;
  
  case NIGHTSLEEP:{

    appState = WAKEFROMNIGHTSLEEP;
    
    // disable pwr to sensors
    gpio_hold_dis(GPIO_NUM_15); // disable lock
    gpio_hold_dis(GPIO_NUM_16); // disable lock
    gpio_hold_dis(GPIO_NUM_17); // disable lock
    digitalWrite(amg_pwr_pin, HIGH);
    digitalWrite(ccs881_pwr_pin, HIGH);
    digitalWrite(audio_pwr_pin, HIGH); 
    gpio_hold_en(GPIO_NUM_15); // lock state 
    gpio_hold_en(GPIO_NUM_16); // lock state 
    gpio_hold_en(GPIO_NUM_17); // lock state 
    gpio_deep_sleep_hold_en(); // to hold state during deepsleep

    //todo
    // change 60 to right time e.g. 17 uur
    
    // sleep until morning
    Serial.println("nightnight");
    goToDeepSleep(60);
    
  }break;

   case WAKEFROMNIGHTSLEEP:{

     appState = WAKESENSORS;

     days_since_sync++;
     
     // sync clock if necessary
     if(days_since_sync > 14){ 
       appState = NTPSYNC;
     }

     //enable power to sensors
    gpio_hold_dis(GPIO_NUM_15); // disable lock
    gpio_hold_dis(GPIO_NUM_16); // disable lock
    gpio_hold_dis(GPIO_NUM_17); // disable lock
    digitalWrite(amg_pwr_pin, LOW);
    digitalWrite(ccs881_pwr_pin, LOW);
    digitalWrite(audio_pwr_pin, LOW); 
    gpio_hold_en(GPIO_NUM_15); // lock state 
    gpio_hold_en(GPIO_NUM_16); // lock state 
    gpio_hold_en(GPIO_NUM_17); // lock state 
    gpio_deep_sleep_hold_en(); // to hold state during deepsleep

    
  }break;
  }
}
