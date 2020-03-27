#ifndef _UTIL_H // must be unique name in the project
#define _UTIL_H

#include <Arduino.h>
#include "esp_wifi.h"// lib for Wi-Fi
#include <WiFi.h>
#include "driver/adc.h"
#include <esp_bt.h>

/* define the differente states of the program */
typedef enum app_states{
  SENDDATA,
  SLEEP,
  READSENSORS,
  IDLE
} APP_State_t;


// functions
void goToDeepSleep(int sec); // disables wifi and adc
bool sendMessage(uint8_t* data, int length);

#endif 
