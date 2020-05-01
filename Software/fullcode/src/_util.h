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
  CHECKTIME,
  NIGHTSLEEP,
  WAKEFROMNIGHTSLEEP
} APP_State_t;


// functions
void goToDeepSleep(int sec); // disables wifi and adc; time in seconds
void goToDeepSleep_ms(int ms); // time in milli seconds
bool sendMessage(float* data, float amgtemp, float audio, uint16_t* css_data, uint8_t id, int length);
void print_wakeup_reason();
void ntp_sync();
void printLocalTime();
int checkhour();

#endif 
