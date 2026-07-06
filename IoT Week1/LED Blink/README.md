# LED Blink with Potentiometer Speed Control 🔆

## 📖 Project Overview

This project blinks an LED at a **variable speed** controlled by a potentiometer. The potentiometer's analog value is read and mapped to a delay range, so turning the knob makes the LED blink faster or slower in real time. Each blink is also counted and logged to the Serial Monitor along with the current blink speed.

## 🎯 Objective

- Read analog input from a potentiometer using `analogRead()`
- Map analog values to a usable output range using `map()`
- Control LED blink timing dynamically based on user input
- Track and display real-time data (blink count and speed) over Serial

## 🛠️ Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| LED | 1 |
| Potentiometer (10kΩ) | 1 |
| Resistor (220Ω) | 1 |
| Jumper Wires | As required |
| Breadboard | 1 |

## 🔌 Circuit Connections

| Component | Arduino Pin |
|---|---|
| LED (Anode) | Pin 13 |
| LED (Cathode) | GND (via resistor) |
| Potentiometer Wiper | A0 |
| Potentiometer Terminal 1 | 5V |
| Potentiometer Terminal 2 | GND |

## ⚙️ How It Works

1. The potentiometer's position is read as an analog value (0–1023) on pin `A0`.
2. `map()` converts this value into a blink delay ranging from **100ms (fast)** to **1000ms (slow)**.
3. The LED on pin 13 turns ON and OFF using this mapped delay, creating a variable blink rate.
4. Each completed blink cycle increments `blinkCount`.
5. The current blink count and speed are printed to the Serial Monitor after every cycle, allowing live monitoring of the LED's behavior.

## 💻 Code

The full sketch is available in [`led_blink_potentiometer.ino`](./led_blink_potentiometer.ino) in this folder.

## 📌 Key Concepts Learned

- Analog input reading with `analogRead()`
- Value mapping/scaling using `map()`
- Real-time Serial communication and data logging
- Using variables to track program state (blink count)
- Basic user-input-driven timing control

## 🚀 Possible Improvements

- Replace blocking `delay()` calls with `millis()` for non-blocking blinking
- Add a reset button to zero out the blink count
- Display blink speed on an LCD instead of Serial Monitor
- Clamp potentiometer readings to handle noisy analog input more reliably

## ✍️ Author

**Rishu Jaiswal**
IoT Summer School 2026 — Week 1
