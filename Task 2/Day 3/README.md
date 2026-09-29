# Task 2 - Day 3

## Wi-Fi Manager

Implemented and tested an ESP32 Wi-Fi Manager.

### Completed
- Created `secrets.h` for Wi-Fi credentials.
- Added `secrets.h` to `.gitignore`.
- Connected ESP32 to Wi-Fi.
- Verified IP address, RSSI, and Wi-Fi channel.
- Tested Wi-Fi disconnection and reconnection with retry backoff.
- Documented SmartConfig and Captive Portal provisioning.

### Security
Wi-Fi credentials are stored in `secrets.h` and are excluded from GitHub using `.gitignore`.
