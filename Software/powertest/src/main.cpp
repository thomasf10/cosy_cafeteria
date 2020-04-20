#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setCpuFrequencyMhz(40);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("new cycle");
  setCpuFrequencyMhz(10);
  delay(500);
  Serial.println("test");
  Serial.println(getApbFrequency());
  setCpuFrequencyMhz(20);
  delay(500);
  Serial.println("test");
  Serial.println(getApbFrequency());
  setCpuFrequencyMhz(40);
  delay(500);
  Serial.println("test");
  Serial.println(getApbFrequency());
  setCpuFrequencyMhz(80);
  delay(500);
  Serial.println("test");
  Serial.println(getApbFrequency());
  delay(500);
  setCpuFrequencyMhz(160);
  Serial.println(getApbFrequency());
  


}
