#include <Arduino.h>
#include <ESP8266WiFi.h>
#include<wpa2_enterprise.h>

#define EAP_IDENTITY "thomas.feys@student.odisee.be" //if connecting from another corporation, use identity@organisation.domain in Eduroam
#define EAP_PASSWORD "Sk8ter_sk8ter" //your Eduroam password
const char* ssid = "ODISEE"; // Eduroam SSID

const uint16_t port = 8091;
const char * host = "10.108.32.79"; // ip of host (ip of laptop)
int counter = 0;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to network: ");
  Serial.println(ssid);
  WiFi.disconnect(true);//disconnect form wifi to set new wifi connection
  WiFi.mode(WIFI_STA);    //init wifi mode

  struct station_config config;
  char ssid[32] = "ODISEE";
  char password[64] = {0x00};
  config.bssid_set = 0;  //need not check MAC address of AP
  memcpy(&config.ssid, ssid, 32);
  memcpy(&config.password, password, 64);

  wifi_station_set_config(&config);
  wifi_station_set_wpa2_enterprise_auth(1); // enable wpa2_enterprise


  wifi_station_set_enterprise_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide username --> identity and username is same
  wifi_station_set_enterprise_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD)); //provide password

  WiFi.begin(ssid); //connect to wifi
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

    //  Serial.printf("New Client. RSSi: %ld dBm\n",WiFi.RSSI()); //print signal strength

    counter++;
    if(counter>=40){ //after 20 seconds timeout - reset board
      ESP.restart();
    }
}
}
void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client;

      if (!client.connect(host, port)) {

          Serial.println("Connection to host failed");

          delay(1000);
          return;
      }

      Serial.println("Connected to server successful!");

      client.print("hello from esp32");

      Serial.println("Disconnecting...");
      client.stop();

      delay(10000);
}
