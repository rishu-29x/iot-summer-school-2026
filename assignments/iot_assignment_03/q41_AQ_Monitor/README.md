# 🏠 Smart Home Air Quality Monitor

🎥 **Video Demo:** [Watch on Loom]

---

## 📖 Project Overview
A family in Milan, Europe, is concerned about indoor air quality during winter when wood is burned for heating. This project implements an **IoT-based Smart Home Air Quality Monitoring System** using an ESP32 that continuously monitors smoke/gas concentration, temperature, and humidity. The system provides local visual and audible alerts based on air quality severity and continues to function fully offline, without requiring an internet connection.

---

## 🎯 Objective
- Continuously monitor smoke/gas concentration using an MQ-2 sensor.
- Measure ambient temperature and humidity using a DHT sensor.
- Classify air quality into three severity levels based on a calibrated baseline.
- Provide real-time visual (RGB LED) and audible (buzzer) alerts.
- Log readings to the Serial Monitor in CSV format for easy analysis.
- Support Bluetooth-based mobile alerts on physical ESP32 hardware.
- Operate reliably without any internet connectivity.

---

## 🧰 Components Used

| Component | Quantity |
|---|:---:|
| ESP32 Dev Module | 1 |
| MQ-2 Gas Sensor | 1 |
| DHT22 Sensor *(used in Wokwi; replace with DHT11 for physical hardware)* | 1 |
| RGB LED (Common Cathode) | 1 |
| Active Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |

---

## 🔌 Circuit Connections

| Component | ESP32 Pin |
|---|---|
| MQ-2 Analog Output | Analog Pin |
| DHT Data Pin | Digital Pin |
| RGB LED — Red | Digital Pin (PWM) |
| RGB LED — Green | Digital Pin (PWM) |
| RGB LED — Blue | Digital Pin (PWM) |
| Buzzer | Digital Pin |

> ℹ️ **Note:** Exact pin numbers should be confirmed against the pin definitions in the `.ino` file, since they may vary between the Wokwi simulation and physical hardware wiring.

---

## ⚙️ How It Works
1. At startup, the MQ-2 sensor is **calibrated** by recording a baseline gas value under normal conditions.
2. During operation, the current gas reading is continuously compared against this baseline.
3. The difference is classified into one of three severity levels:
   - 🟢 **SAFE** — Normal indoor air quality
   - 🟡 **MODERATE** — Elevated smoke levels
   - 🔴 **DANGER** — Unsafe smoke concentration
4. The RGB LED lights up green, yellow, or red to match the detected severity.
5. The buzzer sounds distinct tones for the moderate and danger conditions.
6. Temperature, humidity, gas readings, and severity level are logged to the Serial Monitor in CSV format.
7. On physical ESP32 hardware, alerts are additionally sent to a paired smartphone via the built-in `BluetoothSerial` library. Since Wokwi does not support Bluetooth simulation, a sample mobile alert format is included below for illustration.

---

## 📊 Air Quality Thresholds

| Gas Difference from Baseline | Status |
|---|---|
| Less than 80 | 🟢 SAFE |
| 80 – 249 | 🟡 MODERATE |
| 250 and above | 🔴 DANGER |

---

## 📈 Sample Serial Output
```text
Timestamp, MQ-2 Value, DHT11 Temp, DHT11 Humidity, Severity Level
00:01,220,23.4,49,SAFE
00:02,280,23.5,50,SAFE
00:03,420,23.6,49,MODERATE
00:04,710,23.8,48,DANGER
```

---

## 📱 Sample Bluetooth Alert *(Physical Hardware Only)*
```text
SAFE
Gas:210
Temp:22.8°C
Humidity:51%

WARNING
Moderate Smoke Detected
Gas=430
Check Fireplace

DANGER!!
Smoke Level Critical
Gas=765
Open Windows
Leave Room if Necessary
```

---

## 💻 Code
🔗 [SmartHomeAirQualityMonitor.ino](./SmartHomeAirQualityMonitor.ino)

---

## ✨ Features
- Real-time smoke/gas monitoring
- Temperature and humidity monitoring
- Automatic MQ-2 sensor calibration
- Three-level air quality classification
- RGB LED visual indication
- Three-stage buzzer alarm
- CSV logging through Serial Monitor
- Bluetooth alert support for real ESP32 hardware
- Fully offline operation (no internet required)

---

## 🧠 Key Concepts Learned
- Sensor calibration and baseline-relative threshold classification
- Interfacing with an MQ-2 gas sensor and interpreting analog readings
- Multi-level alerting using RGB LEDs and buzzer tones
- Structuring sensor data as CSV for logging and analysis
- Using `BluetoothSerial` for wireless notifications on ESP32
- Designing IoT systems for reliable offline operation

---

## 🔧 Possible Improvements
- Add a display (OLED/LCD) for on-device readout without needing Serial Monitor access
- Store historical data locally (SD card) for trend analysis over time
- Add Wi-Fi/cloud sync as an optional feature when internet is available
- Build a companion mobile app instead of relying on raw Bluetooth text alerts
- Add multi-point calibration for improved accuracy across different environments

---

**Rishu Jaiswal**
*IoT Summer School 2026 — Week [?]*
