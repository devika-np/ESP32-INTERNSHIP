# ESP32 Internship – Day 2

## Title
Arduino Core for ESP32 & USB Drivers

## Objective

The objective of Day 2 was to set up the ESP32 development environment, verify the USB connection, configure the partition scheme, install the required libraries, and run a basic ESP32 environment check.

## Checklist Completed

### 1. ESP32 Board Package

The ESP32 board package was installed in Arduino IDE.

Board selected:
ESP32 Dev Module

Path:
Tools → Board → ESP32 Dev Module

### 2. USB Cable and COM Port

A USB data cable was used to connect the ESP32 to the computer.

The ESP32 was detected successfully and a stable COM port was available.

COM Port:
COM3

### 3. Partition Scheme

The partition scheme was checked and an OTA-capable partition layout was selected.

Selected partition scheme:
Default 4MB with spiffs (1.2MB APP/1.5MB SPIFFS)

### 4. Required Libraries

The following libraries were installed and verified:

- DHT sensor library by Adafruit
- Adafruit Unified Sensor
- PubSubClient by Nick O'Leary
- ArduinoJson by Benoit Blanchon

These libraries were documented as part of the development environment setup.

### 5. ESP32 Environment Check

The file `day02_env_check.ino` was created and successfully compiled.

The program checks and displays:

- Free Heap
- Chip Model
- Chip Revision
- CPU Frequency
- ESP32 SDK Version

The program was uploaded to the ESP32 and the output was verified using the Serial Monitor at 115200 baud.

## Result

All Day 2 checklist items were completed successfully.

The ESP32 development environment was configured, the USB connection and COM port were verified, the partition scheme was documented, the required libraries were installed, and the environment-check program was successfully uploaded and tested.
