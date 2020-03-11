#include <Arduino.h>

/*
comunnicate to python server
 */

#include <WiFi.h>

#define SERIAL_BUFFER_SIZE 256

#define SIZE        2048
#define TEMP_SIZE   4096

const char* ssid = "DND-LAB-TCGent";
const char* password =  "dndlab.gent";

const uint16_t port = 8091;
const char * host = "192.168.1.12";



int dummy[SIZE];
int data[TEMP_SIZE];

void sendData(){


  //connect to wifi
  WiFiClient client;

      if (!client.connect(host, port)) {

          Serial.println("Connection to host failed");

          delay(1000);
          return;
      }

      Serial.println("Connected to server successful!");
      // send data

      for(int i=0; i<32;i++){
        if(i<10){
          client.print(i);
        }

        //client.print(i);
      }
      client.print("yeet");
      Serial.println("send message to PC");

      Serial.println("Disconnecting...");
      client.stop();
}

void setup()
{
    Serial.begin(115200);
    Serial.print("wifitest");
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}




void loop(){

      sendData();
      delay(10000);
}
