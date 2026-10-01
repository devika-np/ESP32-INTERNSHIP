# NTP Time Synchronization

## Purpose

This document describes how the ESP32 synchronizes its internal clock using Network Time Protocol (NTP) after connecting to Wi-Fi.

## NTP Servers

The ESP32 uses:

- `pool.ntp.org`
- `time.nist.gov`

## Time Zone

The time zone is configured for Indian Standard Time (IST).

UTC offset:

`UTC+05:30`

## Synchronization Process

1. ESP32 starts.
2. ESP32 connects to the configured Wi-Fi network.
3. After Wi-Fi connection is successful, NTP synchronization is started.
4. The ESP32 requests the current time from an NTP server.
5. The obtained time is converted to local IST time.
6. The local time is displayed through the Serial Monitor.
7. An ISO 8601 formatted timestamp is generated for use in JSON data.

## Verification

NTP synchronization was successfully verified through the Serial Monitor.

The output confirmed:

- Wi-Fi connection
- NTP time synchronization
- Correct local time
- ISO timestamp generation

## NTP Failure Behavior

If NTP synchronization fails or the NTP server cannot be reached, the program reports:

`NTP sync failed!`

The ESP32 remains connected to Wi-Fi and can attempt time synchronization again according to the program's retry behavior.

## Result

The ESP32 successfully synchronized its time after connecting to Wi-Fi and generated a usable ISO 8601 timestamp.
