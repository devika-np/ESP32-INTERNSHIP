#include <WiFi.h>
#include "secrets.h"

enum WifiState { WIFI_DISCONNECTED, WIFI_CONNECTING, WIFI_CONNECTED };
WifiState wifiState = WIFI_DISCONNECTED;
unsigned long connectStarted = 0;
uint8_t retryAttempt = 0;
const uint16_t CONNECT_TIMEOUT_MS = 15000;

void startWifiConnect() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  delay(100);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  connectStarted = millis();
  wifiState = WIFI_CONNECTING;
  Serial.printf("Connecting to %s ...\n", WIFI_SSID);
}

void loopWifiManager() {
  if (wifiState == WIFI_CONNECTED) {
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println(F("WiFi lost — reconnecting"));
      wifiState = WIFI_DISCONNECTED;
      retryAttempt = 0;
    }
    return;
  }

  if (wifiState == WIFI_DISCONNECTED) {
    startWifiConnect();
    return;
  }

  if (WiFi.status() == WL_CONNECTED) {
    wifiState = WIFI_CONNECTED;
    retryAttempt = 0;
    Serial.printf("Connected! IP: %s RSSI: %d dBm ch:%d\n",
                  WiFi.localIP().toString().c_str(), WiFi.RSSI(), WiFi.channel());
    return;
  }

  if (millis() - connectStarted > CONNECT_TIMEOUT_MS) {
    WiFi.disconnect(true);
    wifiState = WIFI_DISCONNECTED;
    retryAttempt = min<uint8_t>(retryAttempt + 1, 6);
    uint32_t backoff = (1UL << retryAttempt) * 1000UL;
    Serial.printf("Connect timeout — retry in %lu ms\n", backoff);
    delay(backoff);
  }
}

void setup() {
  Serial.begin(115200);
  delay(200);
}

void loop() {
  loopWifiManager();
  delay(250);
}
