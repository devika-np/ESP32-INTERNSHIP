void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("ESP32 Environment Check");
  Serial.println("-----------------------");

  Serial.print("Free Heap: ");
  Serial.print(ESP.getFreeHeap());
  Serial.println(" bytes");

  Serial.print("Chip Model: ");
  Serial.println(ESP.getChipModel());

  Serial.print("Chip Revision: ");
  Serial.println(ESP.getChipRevision());

  Serial.print("CPU Frequency: ");
  Serial.print(ESP.getCpuFreqMHz());
  Serial.println(" MHz");

  Serial.print("SDK Version: ");
  Serial.println(ESP.getSdkVersion());
}

void loop() {
}