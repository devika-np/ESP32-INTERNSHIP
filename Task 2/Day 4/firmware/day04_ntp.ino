#include <WiFi.h>
#include <time.h>
#include "secrets.h"

enum WifiState { WIFI_DISCONNECTED, WIFI_CONNECTING, WIFI_CONNECTED };
WifiState wifiState = WIFI_DISCONNECTED;

unsigned long connectStarted = 0;
uint8_t retryAttempt = 0;

bool timeSynced = false;
bool ntpConfigured = false;
unsigned long nextNtpRetry = 0;

const uint16_t CONNECT_TIMEOUT_MS = 15000;


// ---------- ISO TIMESTAMP FUNCTION ----------

String isoTimestamp() {
  struct tm timeinfo;

  if (!getLocalTime(&timeinfo, 1000)) {
    return "";
  }

  char timestamp[30];

  strftime(timestamp, sizeof(timestamp),
           "%Y-%m-%dT%H:%M:%S", &timeinfo);

  return String(timestamp) + "+05:30";
}


// ---------- START WIFI CONNECTION ----------

void startWifiConnect() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  delay(100);

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  connectStarted = millis();
  wifiState = WIFI_CONNECTING;

  Serial.printf("Connecting to %s ...\n", WIFI_SSID);
}


// ---------- WIFI MANAGER ----------

void loopWifiManager() {

  // If WiFi is already connected
  if (wifiState == WIFI_CONNECTED) {

    // Check whether WiFi was lost
    if (WiFi.status() != WL_CONNECTED) {

      Serial.println(F("WiFi lost - reconnecting"));

      wifiState = WIFI_DISCONNECTED;
      retryAttempt = 0;

      // Time must be synchronized again after reconnection
      timeSynced = false;
      ntpConfigured = false;
    }

    return;
  }


  // If WiFi is disconnected, start connection
  if (wifiState == WIFI_DISCONNECTED) {
    startWifiConnect();
    return;
  }


  // Check whether WiFi connection succeeded
  if (WiFi.status() == WL_CONNECTED) {

    wifiState = WIFI_CONNECTED;
    retryAttempt = 0;

    Serial.printf("Connected! IP: %s RSSI: %d dBm ch:%d\n",
                  WiFi.localIP().toString().c_str(),
                  WiFi.RSSI(),
                  WiFi.channel());


    // ---------- NTP TIME SYNCHRONIZATION ----------

    if (!timeSynced && millis() >= nextNtpRetry) {

      if (!ntpConfigured) {

        // India Standard Time = UTC + 5 hours 30 minutes
        configTime(19800, 0,
                   "pool.ntp.org",
                   "time.nist.gov");

        ntpConfigured = true;

        Serial.println("Starting NTP time synchronization...");
      }


      struct tm timeinfo;

      // Wait up to 10 seconds for NTP time
      if (getLocalTime(&timeinfo, 10000)) {

        Serial.println("NTP time synchronized!");

        // Print local time
        char localTime[30];

        strftime(localTime,
                 sizeof(localTime),
                 "%Y-%m-%d %H:%M:%S",
                 &timeinfo);

        Serial.print("Local time: ");
        Serial.println(localTime);


        // Print ISO timestamp
        Serial.print("ISO timestamp: ");
        Serial.println(isoTimestamp());

        timeSynced = true;

      } else {

        Serial.println("NTP sync failed - retrying in 5 seconds");

        // Retry after 5 seconds
        nextNtpRetry = millis() + 5000;
      }
    }

    return;
  }


  // ---------- WIFI CONNECTION TIMEOUT ----------

  if (millis() - connectStarted > CONNECT_TIMEOUT_MS) {

    WiFi.disconnect(true);

    wifiState = WIFI_DISCONNECTED;

    retryAttempt = min<uint8_t>(retryAttempt + 1, 6);

    uint32_t backoff = (1UL << retryAttempt) * 1000UL;

    Serial.printf("Connect timeout - retry in %lu ms\n",
                  backoff);

    delay(backoff);
  }
}


// ---------- SETUP ----------

void setup() {

  Serial.begin(115200);

  delay(200);
}


// ---------- MAIN LOOP ----------

void loop() {

  loopWifiManager();

  delay(250);
}
