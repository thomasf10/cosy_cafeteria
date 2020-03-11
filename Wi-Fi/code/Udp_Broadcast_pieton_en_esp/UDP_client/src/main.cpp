#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

#define GPIO_PIN 2

/* WiFi network name and password */
const char * ssid = "DND-LAB-TCGent";
const char * pwd = "dndlab.gent";

// IP address to send UDP data to.
// it can be ip address of the server or
// a network broadcast address
// here is broadcast address
const char * udpAddress = "192.168.1.12";
const int udpPort = 8093;

//create UDP instance
WiFiUDP udp;

void setup(){
  Serial.begin(115200);

  //Connect to the WiFi network
   WiFi.begin(ssid, pwd);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  //This initializes udp and transfer buffer
  udp.begin(udpPort);
}

void loop(){

  //data will be sent to server
  uint8_t receivebuffer[50] = "";
  uint8_t sendbuffer[50] = "yeet server";

  //send packet to server
  udp.beginPacket(udpAddress, udpPort);
  udp.write(sendbuffer, 11);
  udp.endPacket();
  Serial.println("packet send to server");

  //sets 50 bytes of the block of memory pointed to by buffer
  memset(receivebuffer, 0, 50);

  //processing incoming packet, must be called before reading the buffer
  udp.parsePacket();

  //receive response from pythonserver
  if(udp.read(receivebuffer, 50) > 0){
    Serial.print("Server to client: ");
    Serial.println((char *)receivebuffer);
  }

  //Wait for 1 second
  delay(1000);

}
