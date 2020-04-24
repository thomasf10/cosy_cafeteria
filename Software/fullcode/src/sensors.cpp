#include <Arduino.h>
#include <sensor.h>
#include <Arduino.h>
#include <driver/gpio.h>
#include <driver/adc.h>
#include "Adafruit_CCS811.h"
#include "SparkFun_GridEYE_Arduino_Library.h"


#define GPIO_OUTPUT_IO_CCS811    32
#define GPIO_INPUT_IO_AUDIO    33
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<GPIO_OUTPUT_IO_CCS811)
#define GPIO_INPUT_PIN_SEL  (1ULL<<GPIO_INPUT_IO_AUDIO)
#define ESP_INTR_FLAG_DEFAULT 0


 Adafruit_CCS811 sensor_CCS811;
 GridEYE sensor_AMG88;


/*
bool status;
 uint16_t data_CCS811[2];
 double temperature_CCS811=0;
 double* tempCCS = &temperature_CCS811;
 float pixeltemperature[64];
 float temperature_AMG8833=0;
 float* tempAMG = &temperature_AMG8833;
 int audio_level=0;
 int* audio = &audio_level;
*/
/**
 * This function will initialize the CCC811-sensor
 * No input needed and no output will be returned  
 **/
void init_CCS811(){
    
  //INIT the GPIO pins for the sensors
  gpio_config_t io_conf;
  
  io_conf.mode = GPIO_MODE_OUTPUT;
  //bit mask of the pin that you want to set as output,GPIO32 =>nWake_CCS811
  io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
  //configure GPIO with the given settings
  gpio_config(&io_conf);
  
  gpio_pad_select_gpio(GPIO_NUM_32);
    /* Set the GPIO as a push/pull output */
  gpio_set_direction(GPIO_NUM_32, GPIO_MODE_OUTPUT);
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
  // raise nWake to go to sleep
  gpio_hold_dis(GPIO_NUM_32); // disable lock
  gpio_set_level(GPIO_NUM_32, 1);
  gpio_hold_en(GPIO_NUM_32); // lock state 
  gpio_deep_sleep_hold_en(); // to hold state during deepsleep
  
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
  sensor_AMG88.sleep(); // toegevoegd door thomas
}


/**
 * This function will wake both sensors
 * No input needed and no output will be returned  
 **/
void wake_sensors(){
  // Wake CCS811 
  gpio_hold_dis(GPIO_NUM_32); // disable lock
  gpio_set_level(GPIO_NUM_32, 0);
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
void get_measurements_CCS811(uint16_t data[2]){ // double* temperature_CCS811 removed
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

  // After getting the measurements put the sensor immediatly back to sleep, raise nWake
  gpio_hold_dis(GPIO_NUM_32); // disable lock
  gpio_set_level(GPIO_NUM_32, 1);
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
  //init_audio(); 
}

/*
 * Setup of the program
 
void setup() {
    // Enable I²C serial for printing (serial for debug)
  Wire.begin();
  Serial.begin(115200);
  //Initialize the ADC GPIO 33, CCS811 and AMG8833
  init_sensors();
  
}

void loop() {
  //After choosen time may be more then several hours wake the sensors
  wake_sensors();
  //Audio level first avaiable koppeld to ESP32, or the settle time of the detector audiolevel
  get_audio_level(audio);
  //After 105ms the result of the AMG is fully avaiable
  delay(105);
  // Get result AMG after this is read out, the data of CCS811 is avaiable. After data was retrieve sensor will be put into sleep imemdiatly
  get_measurements_AMG8833(pixeltemperature,tempAMG);
  get_measurements_CCS811(data_CCS811,tempCCS);
  //Delay time following run
 delay(5000);
}
 */