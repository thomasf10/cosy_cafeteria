#include <Arduino.h>
/*|----------------------------------------------------------|*/
/*|WORKING EXAMPLE FOR HTTPS CONNECTION                      |*/
/*|TESTED BOARDS: Devkit v1 DOIT, Devkitc v4                 |*/
/*|CORE: June 2018                                           |*/
/*|----------------------------------------------------------|*/
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "esp_wpa2.h"
#include <Wire.h>
#include "driver/adc.h"
#include <esp_wifi.h>
#include <esp_bt.h>

#define EAP_IDENTITY "thomas.feys@student.odisee.be" //if connecting from another corporation, use identity@organisation.domain in Eduroam
#define EAP_PASSWORD "Sk8ter_sk8ter" //your Eduroam password
const char* ssid = "ODISEE"; // Eduroam SSID

const uint16_t port = 8091;
const char * host = "10.108.32.133"; // ip of host (ip of laptop/raspy)
int counter = 0;

/*--------------------------functions-----------------------------*/

void goToDeepSleep(int sec)
{
  Serial.println("Going to sleep...");
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  btStop();

  adc_power_off();
  esp_wifi_stop();
  esp_bt_controller_disable();

  // Configure the timer to wake us up!
  esp_sleep_enable_timer_wakeup(sec * 1000000);

  // Go to sleep! Zzzz
  esp_deep_sleep_start();
}

void sendMessage(int* data, int length){
  //connect to wifi
  bool retry = false;
  bool connected = false;
  while(connected == false){
    WiFi.disconnect(true);  //disconnect form wifi to set new wifi connection
    WiFi.mode(WIFI_STA);
    WiFi.begin();
    //todo: retry functie werkt niet!!!
      while (WiFi.status() != WL_CONNECTED && retry == false) {
        delay(500);
        Serial.print(".");
        counter++;
        if(counter>=10){ //after 5 seconds timeout - reset board
          retry = true;
        }
      }
    if(WiFi.status() == WL_CONNECTED){
      connected = true;
    }
  }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address set: ");
    Serial.println(WiFi.localIP()); //print LAN IP

  WiFiClient client;
    if (!client.connect(host, port)) {
        Serial.println("Connection to host failed");
        delay(1000);
        return;
    }
  Serial.println("Connected to server successful!");
  for(int i=0; i<length;i++){
    client.print(data[i]);
    // if(i<length-1){
    //   client.print(" ");
    // }
   
  }
  client.print("/")
  Serial.println("Disconnecting...");
  client.stop();
  WiFi.disconnect();
}

//WiFiClientSecure client;
void setup() {
  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  esp_wifi_init(&cfg);
  WiFi.mode(WIFI_STA); //init wifi mode
  esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide identity
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide username --> identity and username is same
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD)); //provide password
  esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT(); //set config settings to default
  esp_wifi_sta_wpa2_ent_enable(&config); //set config settings to enable function
  // WiFi.disconnect();
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
  // Serial.print("Connecting to network: ");
  // Serial.println(ssid);
  Serial.println("in setup na sleep??");
  //
  // // set wifi config
  // WiFi.disconnect(true);  //disconnect form wifi to set new wifi connection
  // WiFi.mode(WIFI_STA); //init wifi mode
  // esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide identity
  // esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide username --> identity and username is same
  // esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD)); //provide password
  // esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT(); //set config settings to default
  // esp_wifi_sta_wpa2_ent_enable(&config); //set config settings to enable function


}
void loop() {



      int data[2] = {1,2};
     sendMessage(data,2);
     goToDeepSleep(10);

}
