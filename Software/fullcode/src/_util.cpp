#include "_util.h"
#include <PriUint64.h>
#include "time.h"
#define _UNIX03_SOURCE
#include <stdlib.h>


//for enterprise network wifi connection:
#define EAP_IDENTITY "firstname.lastname@student.odisee.be" //if connecting from another corporation, use identity@organisation.domain in Eduroam
#define EAP_PASSWORD "**************" //your Eduroam password
const char* ssid = "ODISEE"; // Eduroam SSID

// for home network wifi connection:
const char* ssidhome = "telenet-F0116";
const char* pwd = "PVFse1RKYrMT";

// socket
const uint16_t port = 8091;
//const char * host = "192.168.0.107"; // ip python server (ip of laptop)
const char * host = "81.244.156.25"; // ip python server (ip of raspberry pi)

// ntp server
const char* ntpServer = "europe.pool.ntp.org";
const long  gmtOffset_sec = 3600; // 3600 for belgium and most of europe
const int   daylightOffset_sec = 3600; // if country has daylightsavingstime

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

    // Go to sleep! 
    esp_deep_sleep_start();
}

void goToDeepSleep_ms(int ms)
{
    Serial.println("Going to sleep...");
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    btStop();

    adc_power_off();
    esp_wifi_stop();
    esp_bt_controller_disable(); 

    // Configure the timer to wake us up!
    esp_sleep_enable_timer_wakeup(ms * 1000);

    // Go to sleep! 
    esp_deep_sleep_start();
}

bool sendMessage(float* data, float amgtemp, float audio, uint16_t* css_data, uint8_t id, int length){
    WiFi.disconnect(true);  //disconnect form wifi to set new wifi connection
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssidhome,pwd); // no arguments if enterprise wifi is used
        
    int counter = 0;
    Serial.println("connecting to network");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        counter++;
        if(counter>=10){ //after 5 seconds timeout 
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

            // send amg pixels
            for(int i=0;i<length/4;i++){
                client.write((const uint8_t *) & data[i], 4);
            }

            // send amg temp
                client.write((const uint8_t *) & amgtemp, 4);

            // send audio voltage
                client.write((const uint8_t *) & audio, 4);

            // send css811 data
                client.write((const uint8_t *) & css_data[0], 2);
                client.write((const uint8_t *) & css_data[1], 2);

            // send id
                client.write(id);    
                
            client.stop();
            WiFi.disconnect();
            Serial.println("Disconnecting...");
            return true;
        }
    }
}

//Function that prints the reason by which ESP32 has been awaken from sleep
void print_wakeup_reason(){
	esp_sleep_wakeup_cause_t wakeup_reason;
	wakeup_reason = esp_sleep_get_wakeup_cause();
	switch(wakeup_reason)
	{
		case ESP_SLEEP_WAKEUP_EXT0  : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
		case ESP_SLEEP_WAKEUP_EXT1  : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
		case ESP_SLEEP_WAKEUP_TIMER  : Serial.println("Wakeup caused by timer"); break;
		case ESP_SLEEP_WAKEUP_TOUCHPAD  : Serial.println("Wakeup caused by touchpad"); break;
		case ESP_SLEEP_WAKEUP_ULP  : Serial.println("Wakeup caused by ULP program"); break;
		default : Serial.println("Wakeup was not caused by deep sleep"); break;
	}
}

void ntp_sync(){
    //connect to WiFi
    Serial.printf("Connecting to %s ", ssidhome);
    WiFi.begin(ssidhome, pwd);
    int counter = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
         counter++;
        if(counter>=10){ //after 5 seconds timeout 
            Serial.println("connection failed");
            break;
        }
    }
    Serial.println(" CONNECTED");
    
    if(WiFi.status() == WL_CONNECTED){
        //init and get the time
        configTime(0, 0, ntpServer);
        // corrects timezones
        setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
        tzset(); // save the TZ variable

        printLocalTime();
    }else{
        Serial.println("sync failed");
    }

    //disconnect WiFi as it's no longer needed
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
}

void printLocalTime()
{
    // corrects timezones
    setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
    tzset(); // save the TZ variable

    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)){
        Serial.println("Failed to obtain time");
        return;
    }
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}


int checkhour(){
    // corrects timezones
    setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
    tzset(); // save the TZ variable

    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return -1;
    }
    // get hour
    int hour = timeinfo.tm_hour;
    Serial.println("hour");
    Serial.println(hour);
    return hour;
}