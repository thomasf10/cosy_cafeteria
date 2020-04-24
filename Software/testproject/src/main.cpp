#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "esp_wpa2.h"
#include <Wire.h>
#include "driver/adc.h"
#include <esp_wifi.h>
#include <esp_bt.h>

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


void goToDeepSleep_ms(int ms)
{
    Serial.println("Going to sleep...");
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    btStop();

    adc_power_off();
    esp_wifi_stop();
    esp_bt_controller_disable();

    // Configure the timer to wake us up!
    esp_sleep_enable_timer_wakeup(ms * 1000);

    // Go to sleep! Zzzz
    esp_deep_sleep_start();
}

RTC_DATA_ATTR int toggle = LOW;
void setup() {
  // put your setup code here, to run once:
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

  pinMode(2, OUTPUT);
  //toggle = LOW;
}

void loop() {
  // put your main code here, to run repeatedly:
  gpio_hold_dis(GPIO_NUM_2);
  //gpio_deep_sleep_hold_dis();
  toggle = !toggle;
  digitalWrite(2,toggle);

  gpio_hold_en(GPIO_NUM_2);
  gpio_deep_sleep_hold_en();
  goToDeepSleep_ms(2000);


}