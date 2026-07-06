# Seven Segment Display — 0–9 Second Counter ⏱️

## 📖 Project Overview

This project uses a **common cathode 7-segment display** to count from **0 to 9**, holding each digit for one second before moving to the next — functioning as a simple repeating second counter. Each digit is rendered by lighting the correct combination of the display's seven segments (a–g).

## 🎯 Objective

- Understand how a 7-segment display's individual segments (a–g) combine to form digits
- Represent each digit as a binary on/off pattern across 7 segments
- Use 2D arrays to store and look up display patterns efficiently
- Implement simple timed counting logic using `delay()`

## 🛠️ Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| 7-Segment Display (Common Cathode) | 1 |
| Resistors (220Ω) | 7 |
| Jumper Wires | As required |
| Breadboard | 1 |

## 🔌 Circuit Connections

| Segment | Arduino Pin |
|---|---|
| a | Pin 2 |
| b | Pin 3 |
| c | Pin 4 |
| d | Pin 5 |
| e | Pin 6 |
| f | Pin 7 |
| g | Pin 8 |

> **Note:** Since this is a **common cathode** display, the shared cathode pin is connected to GND, and each segment lights up when its corresponding Arduino pin is driven HIGH.

## ⚙️ How It Works

1. The `digits[10][7]` array stores the on/off pattern for each digit 0–9, where each row represents one digit and each column corresponds to a segment (a through g).
2. The `displayDigit()` function looks up the pattern for a given number and writes HIGH or LOW to each segment pin accordingly, lighting up the correct segments.
3. The `clearDisplay()` function turns all segments off, used briefly between counting cycles.
4. In `setup()`, all seven segment pins are configured as outputs and the display starts cleared.
5. In `loop()`, the code counts from 0 to 9, displaying each digit for **1 second** using `displayDigit()` and `delay(1000)`.
6. After reaching 9, the display clears briefly (500ms) before the counting cycle restarts from 0.

## 💻 Code

The full sketch is available in [`9_second_counter_code.ino`](./9_second_counter_code.ino) in this folder.

## 📌 Key Concepts Learned

- 7-segment display wiring and segment-to-pin mapping
- Representing display patterns using 2D boolean arrays
- Common cathode vs. common anode display logic
- Simple timed sequencing using `delay()`
- Writing reusable helper functions (`displayDigit()`, `clearDisplay()`)

## 🚀 Possible Improvements

- Replace `delay()` with `millis()` for non-blocking counting
- Add a second 7-segment display for two-digit counting (00–99)
- Add a button to start/stop/reset the counter
- Extend the pattern table to support hexadecimal digits (A–F)

## ✍️ Author

**Rishu Jaiswal**
IoT Summer School 2026 — Week 2
