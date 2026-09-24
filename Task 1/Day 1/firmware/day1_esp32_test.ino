void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("ESP32 test started!");
  Serial.println("Flashing successful.");
}

void loop() {
  Serial.println("ESP32 is running...");
  delay(1000);
}
