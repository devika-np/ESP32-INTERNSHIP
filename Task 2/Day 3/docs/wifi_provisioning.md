# Wi-Fi Provisioning: SmartConfig vs Captive Portal

## SmartConfig

SmartConfig is a Wi-Fi provisioning method where a mobile application sends the Wi-Fi SSID and password to the ESP32 over the wireless network.

### Advantages
- No physical connection to the ESP32 is required.
- Easy to use with a mobile application.
- Suitable for devices that have no display or keyboard.

### Disadvantages
- Requires a compatible mobile application.
- Provisioning can be affected by Wi-Fi compatibility and network conditions.
- The user must have access to the provisioning application.

## Captive Portal

A captive portal creates a temporary Wi-Fi access point on the ESP32. The user connects to this access point and a web page opens where the Wi-Fi SSID and password can be entered.

### Advantages
- Does not require a dedicated mobile application.
- Can be configured using a normal web browser.
- Provides a simple interface for entering Wi-Fi credentials.

### Disadvantages
- The ESP32 must temporarily operate as an access point.
- The user has to connect to the ESP32's temporary Wi-Fi network.
- The web interface requires additional implementation.

## Comparison

| Feature | SmartConfig | Captive Portal |
|---|---|---|
| User interface | Mobile application | Web browser |
| Extra application | Required | Not required |
| ESP32 temporary AP | Not required | Required |
| Configuration method | Wireless provisioning | Web-based configuration |
| Suitable for | Mobile-based setup | Browser-based setup |

## Conclusion

Both methods can be used to provision Wi-Fi credentials to an ESP32. SmartConfig is useful when a compatible mobile application is available, while a captive portal is useful when configuration through a normal web browser is preferred.
