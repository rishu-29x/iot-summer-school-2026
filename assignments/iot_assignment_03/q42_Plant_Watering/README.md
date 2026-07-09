# 🌱 Automated Plant Watering System

🎥 **Video Demo:** [Watch on Loom]

---

## 📖 Project Overview
A horticulture farmer in Jammu & Kashmir wants to automate irrigation for a small saffron farm plot. Since saffron is highly sensitive to overwatering, this project builds an **ESP32-based smart irrigation system** that monitors soil moisture, ambient light, and live weather data to water plants only when truly necessary — while still allowing the farmer to manually trigger irrigation whenever required.

---

## 🎯 Objective
- Monitor soil moisture and classify it into dry, optimal, or wet zones.
- Detect overcast/rainy conditions using an LDR as a local rain proxy.
- Check live rain status using the OpenWeatherMap REST API.
- Automatically water the plant only when soil is dry **and** no rain is detected.
- Allow manual irrigation override via a push button, with a safety lockout.
- Display live status on a 16×2 I2C LCD.
- Log all readings to Google Sheets over Wi-Fi.

---

## 🧰 Components Used

| Component | Quantity |
|---|:---:|
| ESP32 Dev Module | 1 |
| Potentiometer *(soil moisture simulation)* | 1 |
| LDR | 1 |
| Push Button | 1 |
| Green LED *(pump simulation)* | 1 |
| 220Ω Resistor | 1 |
| 16×2 I2C LCD | 1 |
| Jumper Wires | As required |

---

## 🔌 Circuit Connections

| Component | ESP32 Pin |
|---|---|
| Potentiometer | GPIO34 |
| LDR | GPIO35 |
| Push Button | GPIO18 |
| Pump LED | GPIO19 |
| LCD SDA | GPIO21 |
| LCD SCL | GPIO22 |

> ℹ️ **Note:** ESP32 was chosen over ESP8266 because the project requires **two analog inputs** (soil moisture and LDR), while the ESP8266 only provides a single ADC pin.

---

## ⚙️ How It Works
1. The ESP32 continuously reads the potentiometer value, simulating soil moisture, and classifies it as **DRY**, **OPTIMAL**, or **WET**.
2. If the soil is classified as dry, the system checks two independent rain indicators before deciding to water:
   - The **LDR** reading, which detects overcast/low-light conditions locally.
   - The **OpenWeatherMap REST API**, which reports current rain status for the location.
3. If either method indicates rain, watering is **skipped** to prevent overwatering.
4. If the soil is dry and no rain is detected, the pump (simulated via a green LED) is activated to water the plant.
5. A push button allows **manual irrigation override** at any time; after activation, a **5-minute lockout** prevents repeated watering.
6. The 16×2 I2C LCD continuously displays the soil moisture percentage, current operating mode, and elapsed time since the last watering event.
7. All sensor readings and irrigation events are logged to **Google Sheets** via Wi-Fi, using an HTTP GET request to a Google Apps Script endpoint.

---

## 🌦️ Irrigation Decision Flow
```text
Read Soil Moisture
        │
        ▼
   Is Soil DRY?
        │
       Yes
        │
        ▼
Check LDR + Weather API
        │
   ┌────┴────┐
   │         │
 Rain?    No Rain
   │         │
   ▼         ▼
 Skip     Water Plant
```

---

## 📊 Soil Moisture Zones

| Moisture (%) | Status |
|---|---|
| 0 – 29% | 🌵 DRY |
| 30 – 69% | ✅ OPTIMAL |
| 70 – 100% | 💧 WET |

---

## 🌧️ Rain Detection
The system uses two independent methods to determine rainfall conditions:
- **LDR** — detects overcast or low-light conditions locally.
- **OpenWeatherMap REST API** — checks current weather information for the configured location.

Watering is skipped whenever **either** method indicates rain.

---

## 📺 LCD Display
Example output:
```text
M:45% DRY
Last:120s
```

---

## ☁️ Google Sheets Logging
Sensor readings are uploaded using **Wi-Fi → HTTP GET → Google Apps Script → Google Sheets**.

Each log entry contains:
- Timestamp
- Moisture Percentage
- Moisture Status
- Rain Status
- Last Watered Time

---

## 📚 Libraries Used
- `WiFi.h`
- `HTTPClient.h`
- `ArduinoJson`
- `Wire.h`
- `LiquidCrystal_I2C`

---

## ⚠️ Simulation Notes
This project was developed using **Wokwi**. To accommodate simulator limitations:
- A **potentiometer** simulates the soil moisture sensor, since Wokwi does not provide a native soil moisture sensor component.
- A **green LED** simulates the relay-controlled water pump.
- **ESP32** was used instead of ESP8266 to support the two required analog inputs (soil moisture + LDR).

These substitutions preserve the intended system functionality while enabling complete simulation.

---

## 💻 Code
🔗 [Plant_Watering.ino](./Plant_Watering.ino)

---

## ✨ Features
- Automatic irrigation
- Soil moisture monitoring
- LDR-based rain detection
- Weather API integration
- Manual watering override
- 5-minute safety lockout
- LCD status display
- Google Sheets cloud logging
- Offline decision-making using LDR when internet is unavailable

---

## 🧠 Key Concepts Learned
- Combining local sensors (LDR) with cloud data (weather API) for a more reliable automated decision
- Simulating unavailable Wokwi components using suitable substitutes (potentiometer, LED)
- Implementing safety lockouts to prevent repeated/unwanted actuation
- Interfacing with a 16×2 I2C LCD using `LiquidCrystal_I2C`
- Logging structured sensor data to Google Sheets via Google Apps Script
- Choosing hardware (ESP32 vs ESP8266) based on analog input requirements

---

## 🔧 Possible Improvements
- Replace the potentiometer with an actual capacitive/resistive soil moisture sensor on physical hardware
- Add a real relay module and water pump for physical deployment
- Add historical trend charts in Google Sheets or a connected dashboard
- Introduce configurable moisture thresholds per plant type
- Add low-power/sleep modes for extended battery-powered field deployment

---

**Rishu Jaiswal**
*IoT Summer School 2026 - IoT Assignment 3
