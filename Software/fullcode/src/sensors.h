#ifndef SENSORS // must be unique name in the project
#define SENSORS
#include <Arduino.h>
#include <driver/gpio.h>
#include <driver/adc.h>
#include "Adafruit_CCS811.h"
#include "SparkFun_GridEYE_Arduino_Library.h"





void init_CCS811();
void init_audio();
void init_AMG8833();
void wake_sensors();
void get_measurements_CCS811(uint16_t data[2], double* temperature_CCS811);
void get_measurements_AMG8833(float* pixeltemperature, float* temperature_AMG8833);
void get_audio_level(int* level);
void init_sensors();




#endif 