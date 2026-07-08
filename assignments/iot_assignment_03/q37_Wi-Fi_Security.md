**Q37. Wi-Fi Security for IoT
Research and write 250 words on: Common Wi-Fi attack vectors on IoT devices (WPA2 vulnerabilities, evil twin attacks), Best practices for securing ESP32 Wi-Fi connections (certificate pinning, WPA3), and Why hardcoding passwords in IoT source code is dangerous. Reference at least 2 sources in your answer.**


**Ans:**
**Common Wi-Fi Attack Vectors on IoT Devices**

Most IoT devices still rely on WPA2, and its four way handshake has a well known flaw known as KRACK. This lets an attacker force the reinstallation of an already used encryption key, which can allow interception of network traffic since KRACK exploits vulnerabilities in the WPA2 protocol, meaning any device that connects to Wi-Fi and uses WPA2 is potentially at risk. Many IoT devices never receive firmware patches, so the problem persists long after it was disclosed since embedded devices like cameras, routers, and smart home devices that never received KRACK patches remain vulnerable even today.

Another common vector is the evil twin attack, where an attacker sets up a fake access point with the same SSID as a trusted network. Devices that auto connect based on SSID name alone can be tricked into joining this rogue AP, exposing credentials and data to the attacker.

**Securing ESP32 Wi-Fi Connections**

A few practical steps for ESP32 based projects:

1. Use WPA3 wherever the network supports it, since it uses Simultaneous Authentication of Equals, which is resistant to offline dictionary attacks even if a handshake is captured.
2. Enable certificate pinning for any TLS/MQTT connection, so the device only trusts a specific known server certificate instead of any CA signed one.
3. Turn on Protected Management Frames, since ESP32 supports PMF to stop deauthentication and disassociation style attacks.
4. Avoid disabling TLS verification just to fix connection errors, a common shortcut that removes the protection entirely.

**Why Hardcoding Passwords Is Dangerous**

Hardcoding Wi-Fi or server credentials directly in firmware means anyone who dumps the flash memory can extract them instantly. Since the same firmware is often flashed across hundreds of devices, one leaked binary compromises the entire deployment at once. Credentials should instead be provisioned securely at setup time or stored using encrypted flash/NVS with per device keys.

**Sources:**
1. Sucuri, "What is a KRACK attack?"
2. Hologram, "KRACK IoT: How the Latest Widespread Wifi WPA2 Vulnerability is Affecting the Internet of Things"
