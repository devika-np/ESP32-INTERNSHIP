# Day 4 – NTP Time Synchronization

## Objective

To synchronize the ESP32 internal clock with an NTP server after establishing a Wi-Fi connection and generate local time and ISO 8601 timestamps.

## Tasks Completed

- Connected ESP32 to Wi-Fi.
- Configured NTP synchronization using `pool.ntp.org` and `time.nist.gov`.
- Set the time zone to IST (UTC+05:30).
- Verified successful NTP synchronization through the Serial Monitor.
- Displayed the correct local time.
- Generated an ISO 8601 formatted timestamp.
- Integrated time synchronization into the combined Wi-Fi sketch.
- Added handling for NTP synchronization failure.

## NTP Configuration

The ESP32 uses the following NTP servers:

- `pool.ntp.org`
- `time.nist.gov`

The time zone offset used is UTC+05:30 for Indian Standard Time (IST).

## Verification

The Serial Monitor was used to verify:

- Wi-Fi connection
- NTP synchronization
- Local time
- ISO timestamp

## NTP Failure Behavior

If the NTP server cannot be reached, the ESP32 reports:

`NTP sync failed!`

The Wi-Fi connection remains available while time synchronization can be retried according to the program's retry behavior.

## Result

NTP time synchronization was successfully tested. The ESP32 obtained the correct local time and generated an ISO 8601 timestamp after connecting to Wi-Fi.
