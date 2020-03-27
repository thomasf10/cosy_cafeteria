#include "_util.h"


//for enterprise network wifi connection:
#define EAP_IDENTITY "thomas.feys@student.odisee.be" //if connecting from another corporation, use identity@organisation.domain in Eduroam
#define EAP_PASSWORD "Sk8ter_sk8ter" //your Eduroam password
const char* ssid = "ODISEE"; // Eduroam SSID

// for home network wifi connection:
const char* ssidhome = "telenet-F0116";
const char* pwd = "PVFse1RKYrMT";

// socket
const uint16_t port = 8091;
const char * host = "192.168.0.107"; // ip of host (ip of laptop/raspy)

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

bool sendMessage(uint8_t* data, int length){

  volatile bool retry = false;
  volatile bool succes = false;
  WiFi.disconnect(true);  //disconnect form wifi to set new wifi connection
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssidhome,pwd); // no arguments for enterprise wifi
  
  //todo: retry functie werkt niet!!!
  int counter = 0;
  Serial.println("connecting to network");
  while (WiFi.status() != WL_CONNECTED && retry == false) {
      delay(500);
      Serial.print(".");
      counter++;
      if(counter>=10){ //after 5 seconds timeout - reset board
          Serial.println("connection failed");
          break;
      }
  }

  if(WiFi.status() == WL_CONNECTED){
      Serial.println("");
      Serial.println("WiFi connected");
      Serial.println("IP address set: ");
      Serial.println(WiFi.localIP()); //print LAN IP
      WiFiClient client;
      if (!client.connect(host,port)) {
          Serial.println("Connection to server failed");
          delay(1000);
          client.stop();
          return false;
      }else{
          Serial.println("Connected to server successful!");
          client.write(data, length);
          Serial.println("Disconnecting...");
          client.stop();
          WiFi.disconnect();
          return true;
      }
  }
  
}