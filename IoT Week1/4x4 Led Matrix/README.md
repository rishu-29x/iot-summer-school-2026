# 4x4 LED Matrix — Display Characters 🔤

## 📖 Project Overview

This project uses a **4x4 LED matrix** to display custom characters and patterns through row-column multiplexing. Each frame is built by rapidly scanning through the rows and lighting up the correct columns for that row, creating the illusion of a fully static image thanks to persistence of vision.

The matrix cycles through a sequence of characters — including custom letters and a smiley face — each held on screen for a set duration before switching to the next.

## 🎯 Objective

- Understand how an LED matrix is wired using anodes (rows) and cathodes (columns)
- Implement multiplexing to control multiple LEDs with limited digital pins
- Represent characters and patterns as binary grids in code
- Control display timing using `millis()` instead of blocking `delay()` calls

## 🛠️ Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| 4x4 LED Matrix | 1 |
| Jumper Wires | As required |
| Breadboard | 1 |
| Resistors (220Ω, if needed) | 4–16 |

## 🔌 Circuit Connections

| Matrix Line | Arduino Pin | Type |
|---|---|---|
| Row 1 | Pin 2 | Anode (+) |
| Row 2 | Pin 3 | Anode (+) |
| Row 3 | Pin 4 | Anode (+) |
| Row 4 | Pin 5 | Anode (+) |
| Col 1 | Pin 6 | Cathode (−) |
| Col 2 | Pin 7 | Cathode (−) |
| Col 3 | Pin 8 | Cathode (−) |
| Col 4 | Pin 9 | Cathode (−) |

> **Note:** Rows are driven HIGH to activate, while columns are pulled LOW to complete the circuit and light the corresponding LED (active-low columns, active-high rows).

## ⚙️ How It Works

1. Each character is defined as a **4x4 binary grid** (`1` = LED on, `0` = LED off).
2. The `displayPattern()` function scans through the rows one at a time:
   - All rows are set LOW (off).
   - The current row is set HIGH (activated).
   - Each column is set LOW or HIGH depending on whether that LED should light up.
   - A short 2ms delay holds the row before moving to the next, refreshing the full matrix roughly every 8ms — fast enough to appear as a stable image to the human eye.
3. The `loop()` function cycles through each character/pattern for a fixed duration:
   - Letter **C** → 2 seconds
   - Letter **A** → 2 seconds
   - Letter **R** (or your own initial) → 2 seconds
   - Smiley face → 1.5 seconds
   - All LEDs on → 1 second

## 💻 Code

The full sketch is available in [`led_matrix_display.ino`](./code.ino) in this folder.

## 📌 Key Concepts Learned

- Row-column multiplexing for controlling multiple LEDs with fewer pins
- Representing visual patterns as 2D binary arrays
- Non-blocking timing logic using `millis()`
- Active-high vs. active-low pin logic
- Persistence of vision as a display technique

## 🚀 Possible Improvements

- Add more custom characters or a scrolling text feature
- Use shift registers (e.g., 74HC595) to reduce pin usage
- Adjust refresh rate for smoother or brighter display
- Add button input to manually cycle through patterns

## ✍️ Author

**Rishu Jaiswal**
IoT Summer School 2026 — Week 1
