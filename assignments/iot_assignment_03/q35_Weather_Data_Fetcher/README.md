# 🌦️ ESP32 REST API Weather Data Fetcher

## 📖 Project Overview
This project uses an **ESP32** to fetch real-time weather data from the **OpenWeatherMap REST API** and compares it against local environmental readings from a **DHT11 sensor**. The system connects to Wi-Fi, retrieves live weather information (city, description, temperature, humidity), reads local sensor data, and displays a side-by-side comparison — including the exact difference between API and local readings — on the Serial Monitor.

---

## 🎯 Objective
- Connect the ESP32 to a Wi-Fi network.
- Fetch live weather data using the OpenWeatherMap REST API.
- Read local temperature and humidity using a DHT11 sensor.
- Compare API readings with local sensor values.
- Display the results clearly on the Serial Monitor.

---

## 🧰 Components Used

| Component | Quantity |
|---|:---:|
| ESP32 Dev Module | 1 |
| DHT11 Temperature & Humidity Sensor *(DHT22 used for simulation)* | 1 |
| Jumper Wires | As needed |
| Breadboard | 1 *(optional)* |

---

## 🔌 Circuit Connections

| DHT11 Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO 33 |

> ℹ️ **Note:** Ensure the DHT sensor library is configured for the correct sensor type (DHT11 or DHT22) to avoid inaccurate readings.

---

## 📚 Libraries Used
- `WiFi.h`
- `HTTPClient.h`
- `ArduinoJson`
- `DHT Sensor Library` (Adafruit)
- `Adafruit Unified Sensor`

---

## ⚙️ How It Works
1. The ESP32 connects to the configured Wi-Fi network using credentials stored in `config.h`.
2. An HTTP GET request is sent to the OpenWeatherMap REST API for the specified city.
3. The JSON response is parsed using **ArduinoJson** to extract weather description, temperature, and humidity.
4. The DHT11 sensor simultaneously takes a local temperature and humidity reading.
5. The code calculates the difference between the API values and the local sensor values.
6. All results — city, weather description, API readings, local readings, and differences — are printed to the Serial Monitor.

---

## 🖥️ Sample Output
```text
City: Jammu
Weather: Broken Clouds
API Temperature: 40.65 °C
Local Temperature: 24.00 °C
Temperature Difference: -16.65 °C
API Humidity: 22 %
Local Humidity: 59 %
Humidity Difference: 37 %
```

---

## 🚀 Setup Instructions
1. Install all required libraries listed above via the Arduino Library Manager.
2. Create a `config.h` file containing:
   - Wi-Fi SSID
   - Wi-Fi Password
   - OpenWeatherMap API Key
   - City Name
3. Upload `WeatherFetcher.ino` to the ESP32.
4. Open the Serial Monitor at **115200 baud** to view live output.

---

## 🔒 Security Note
The actual `config.h` file is excluded from version control via `.gitignore` to prevent exposing Wi-Fi credentials and the OpenWeatherMap API key. A `config.example.h` template is provided instead.

---

## 📁 Project Structure
```
WeatherFetcher/
│
├── WeatherFetcher.ino
├── config.example.h
├── README.md
├── .gitignore
└── screenshot.png
```

---

## 💻 Code
🔗 [Weather_Data_Fetcher.ino](./Weather_Data_Fetcher.ino)

---

## ✨ Features
- Live weather retrieval using REST API
- Local temperature and humidity monitoring
- API vs. local sensor comparison
- Automatic Wi-Fi connection
- JSON parsing using ArduinoJson
- Secure configuration management

---

## 🧠 Key Concepts Learned
- Making HTTP GET requests from an ESP32 using `HTTPClient`
- Parsing JSON API responses with `ArduinoJson`
- Reading and calibrating DHT11/DHT22 sensor data
- Managing sensitive credentials securely with `.gitignore`
- Comparing real-world sensor accuracy against cloud-based API data

---

## 🔧 Possible Improvements
- Display results on an OLED/LCD screen instead of only the Serial Monitor
- Add error handling for failed API requests or Wi-Fi disconnects
- Log historical comparison data to an SD card or cloud database
- Support multiple cities or auto-detect location via IP geolocation

---

**Rishu Jaiswal**
*IoT Summer School 2026 — Week 3*
