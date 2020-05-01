#include <Arduino.h>
#include <driver/gpio.h>
#include <driver/adc.h>
#include <WiFi.h>
#include <esp_wifi.h>
#include <esp_bt.h>
#include "Adafruit_CCS811.h"
#include "SparkFun_GridEYE_Arduino_Library.h"
#include "sensors.h"


#define GPIO_OUTPUT_IO_CCS811    32
#define GPIO_INPUT_IO_AUDIO    33
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<GPIO_OUTPUT_IO_CCS811)
#define GPIO_INPUT_PIN_SEL  (1ULL<<GPIO_INPUT_IO_AUDIO)
#define ESP_INTR_FLAG_DEFAULT 0

  


 bool status;
 uint16_t data_CCS811[2];
 double temperature_CCS811=0;
 double* tempCCS = &temperature_CCS811;
 float pixeltemperature[64];
 float temperature_AMG8833=0;
 float* tempAMG = &temperature_AMG8833;
 int audio_level=0;
 int* audio = &audio_level;


void goToDeepSleep_ms(int ms)
{
    Serial.println("Going to sleep...");
/*     WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    btStop();

    adc_power_off();
    esp_wifi_stop();
    esp_bt_controller_disable();
 */
    // Configure the timer to wake us up!
    esp_sleep_enable_timer_wakeup(ms * 1000);

    // Go to sleep! Zzzz
    esp_deep_sleep_start();
}


//Function that prints the reason by which ESP32 has been awaken from sleep
void print_wakeup_reason(){
	esp_sleep_wakeup_cause_t wakeup_reason;
	wakeup_reason = esp_sleep_get_wakeup_cause();
	switch(wakeup_reason)
	{

		case ESP_SLEEP_WAKEUP_EXT0  : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
		case ESP_SLEEP_WAKEUP_EXT1  : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
		case ESP_SLEEP_WAKEUP_TIMER  : Serial.println("Wakeup caused by timer"); break;
		case ESP_SLEEP_WAKEUP_TOUCHPAD  : Serial.println("Wakeup caused by touchpad"); break;
		case ESP_SLEEP_WAKEUP_ULP  : Serial.println("Wakeup caused by ULP program"); break;
		default : Serial.println("Wakeup was not caused by deep sleep"); break;
	}
}

/**
 * Setup of the program
 **/
void setup() {

  // Enable I²C serial for printing (serial for debug)
  Wire.begin();

    Serial.begin(115200);
  Serial.println("setuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuup");
  //Print the wakeup reason for ESP32
	print_wakeup_reason();
  
  //Initialize the ADC GPIO 33, CCS811 and AMG8833
  init_sensors();
  
}

/**
 * Measurement loop
 **/
void loop() {
  //After choosen time may be more then several hours wake the sensors
  wake_sensors();
  //Audio level first avaiable koppeld to ESP32, or the settle time of the detector audiolevel
  get_audio_level(audio);
  //After 105ms the result of the AMG is fully avaiable
  delay(105);
  // Get result AMG after this is read out, the data of CCS811 is avaiable. After data was retrieve sensor will be put into sleep imemdiatly
  get_measurements_AMG8833(pixeltemperature,tempAMG);
  get_measurements_CCS811(data_CCS811);

      // print sensor data
    
    Serial.print("audio voltage: ");
    Serial.println(*audio);

    Serial.println("AMG pixels: ");
    for(int i=0; i<64; i++){
      Serial.print(pixeltemperature[i]);
      Serial.print(" : ");
    }
    Serial.println(" ");

    Serial.print(" AMG temp: ");
    Serial.println(*tempAMG);

    Serial.print("CO2: ");
    Serial.println(data_CCS811[0]);
    Serial.print("TVOC: ");
    Serial.println(data_CCS811[1]);

    //Delay time following run
    goToDeepSleep_ms(5000);
   
}