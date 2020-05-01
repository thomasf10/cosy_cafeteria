#include <Arduino.h>
#include <sensor.h>
#include <Arduino.h>
#include <driver/gpio.h>
#include <driver/adc.h>
#include "Adafruit_CCS811.h"
#include "SparkFun_GridEYE_Arduino_Library.h"

 Adafruit_CCS811 sensor_CCS811;
 GridEYE sensor_AMG88;

/**
 * This function will initialize the CCC811-sensor
 * No input needed and no output will be returned  
 **/
void init_CCS811(){

  // Pin IO32 is for the CCS811_nWake 
  gpio_hold_dis(GPIO_NUM_32); // disable lock
  gpio_set_level(GPIO_NUM_32, 0);
  gpio_hold_en(GPIO_NUM_32); // lock state 
  gpio_deep_sleep_hold_en(); // to hold state during deepsleep
  

  bool status = false;
  do{
    Serial.println("Try to initialize CCS811");
    status = sensor_CCS811.begin();
  }
  while(status == false) ;
  sensor_CCS811.setDriveMode(CCS811_DRIVE_MODE_250MS);
}

/**
 * This function will initialize GPIO33 as ADC-input
 * No input needed and no output will be returned  
 **/
void init_audio(){
    adc_power_on();
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_5,ADC_ATTEN_DB_0);   
}

/**
 * This function will initialize the AMG8833-sensor
 * No input needed and no output will be returned  
 **/
void init_AMG8833(){
  sensor_AMG88.begin();
}


/**
 * This function will wake both sensors
 * No input needed and no output will be returned  
 **/
void wake_sensors(){
  // Wake CCS811 
  gpio_hold_dis(GPIO_NUM_32); // disable lock
  digitalWrite(32,LOW);
  gpio_hold_en(GPIO_NUM_32); // lock state 
  gpio_deep_sleep_hold_en(); // to hold state during deepsleep
  // Wake AMG8833 
  sensor_AMG88.wake();
}


/**
 * This function will get the measurements from the CCS811, start delay 1ms
 * Input:  2 element array of the type uint16_t
 *  & pointer a double for the temperature
 * Output: None will be returned but the result will be set in the array and pointer 
 **/
void get_measurements_CCS811(uint16_t data[2]){ 
  //Check is the data avaiable, wait for every check 10ms
  bool status = false;
  do {
    delay(1);
    status= sensor_CCS811.available();
  }
  while (status == false);
  /*
  // not used because the temperature sensor of the amg8833 will be used
  // Calculate the temperature with the NTC-resistor applied.
  *temperature_CCS811 = sensor_CCS811.calculateTemperature();
*/
  // Get the de eCO2- en TVOC-concentration, write to the array CCS811 array.
  sensor_CCS811.readData();
  data[1]= sensor_CCS811.geteCO2();
  data[0]= sensor_CCS811.getTVOC();

  sensor_CCS811.setDriveMode(CCS811_DRIVE_MODE_IDLE);

  // After getting the measurements put the sensor immediatly back to sleep, raise nWake
  gpio_hold_dis(GPIO_NUM_32); // disable lock
  digitalWrite(32,HIGH);
  gpio_hold_en(GPIO_NUM_32); // lock state 
  gpio_deep_sleep_hold_en(); // to hold state during deepsleep
}


/**
 * This function will get the measurements from the AMG8833, start delay 10ms
 * Input:  64 element array of the type float
 *  & pointer a double for the temperature
 * Output: None will be returned but the result will be set in the array and pointer 
 **/
void get_measurements_AMG8833(float* pixeltemperature, float* temperature_AMG8833){
  float data[2];
  //Check if the sensor has his data ready (first and last measurement not 0)
   
  do{
    data[1] = sensor_AMG88.getPixelTemperatureRaw(63);
    data[0] = sensor_AMG88.getPixelTemperatureRaw(0);
  }
  while (data[0]==0 and data[1]==0);
  
  // When data is avaiable => het all pixels one by one
  for (int i = 0; i < 64; i++){
    pixeltemperature[i]=sensor_AMG88.getPixelTemperature(i);
  }
  //Get temperature of the AMG8833
  *temperature_AMG8833= sensor_AMG88.getDeviceTemperature();
  
  //After getting the measurements put the sensor immediatly back to sleep
  sensor_AMG88.sleep();
}


/**
 * This function will get level of the microphone from the ADC1 of th ESP32
 * Input:  pointer to the audiolevel variable if the type integer
 * Output: None will be returned but the result will be set ion the array and pointer 
 **/
void get_audio_level(int* level){
  init_audio();
  *level = adc1_get_raw(ADC1_CHANNEL_5);
}  

/**
 * This is a call function. This will call all the initial function for the seperate parts
 * Input & Output: None
 **/
void init_sensors(){
  init_CCS811();
  init_AMG8833();
}

