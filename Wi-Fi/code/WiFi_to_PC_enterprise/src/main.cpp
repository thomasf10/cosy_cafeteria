#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "esp_wpa2.h"
#include <Wire.h>
#include "driver/adc.h"
#include <esp_wifi.h>
#include <esp_bt.h>
#include "_util.h"






//WiFiClientSecure client;
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

}
void loop() {
  uint8_t data[10];
  for(int i=0; i<10;i++){
    data[i] = i;
  }
  sendMessage(data,10);
  goToDeepSleep(10);

}
