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

RTC_DATA_ATTR int bootCount = 0; // to store data in rtc memory when entering deepsleep



// declare appstate
RTC_DATA_ATTR static volatile APP_State_t appState = SENDDATA;



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

}


void loop() {

  switch (appState)
  {
  case SENDDATA:{
    appState = SLEEP;// set next appstate
     float data[64]; 
    for(int i=0; i<64;i++){
      data[i] = i+20.25;
      Serial.println(data[i]);
    }

    int length = sizeof(data);
    Serial.print("lengte: ");
    Serial.println(length);
    int ctr = 0;
    while(true){  
      if(sendMessage(data,length)){
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
    appState = SENDDATA;
    goToDeepSleep(5);
  }break;

  case NTPSYNC:{
    Serial.println("IN SYNC");
     ntp_sync();
     appState = PRINTTIME;
     goToDeepSleep(10);
  }break;

  case PRINTTIME:{
    Serial.println("IN PRINT");
    printLocalTime();
    checkhour();
    goToDeepSleep(10);
  }break;
  
  case READSENSORS:{

  }break;
  
  case IDLE:{
    delay(500);
  }break;
  }
}
