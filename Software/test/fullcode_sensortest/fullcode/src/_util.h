#ifndef _UTIL_H // must be unique name in the project
#define _UTIL_H

#include <Arduino.h>
#include "esp_wifi.h"// lib for Wi-Fi
#include <WiFi.h>
#include "driver/adc.h"
#include <esp_bt.h>
#include "time.h"

/* define the differente states of the program */
typedef enum app_states{
  SENDDATA,
  SLEEP,
  WAKESENSORS,
  READSENSORS,
  NTPSYNC,
  PRINTTIME,
  IDLE
} APP_State_t;


// functions
void goToDeepSleep(int sec); // disables wifi and adc; time in seconds
void goToDeepSleep_ms(int ms); // time in milli seconds
bool sendMessage(float* data, int length);
void print_wakeup_reason();
void ntp_sync();
void printLocalTime();
void checkhour();

#endif 
