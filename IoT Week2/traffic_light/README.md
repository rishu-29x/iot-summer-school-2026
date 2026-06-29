# 🚦 Traffic Light Controller

An Arduino-based traffic light simulator with a **pedestrian button override** — press the button at any point during the cycle and the light immediately forces RED for pedestrian crossing safety.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Circuit Diagram](#circuit-diagram)
- [Pin Configuration](#pin-configuration)
- [How It Works](#how-it-works)
- [Light Cycle Timing](#light-cycle-timing)
- [Serial Monitor Output](#serial-monitor-output)
- [Getting Started](#getting-started)
- [Code Structure](#code-structure)
- [Author](#author)

---

## Overview

This project simulates a real-world traffic light controller using an Arduino. It cycles through RED, YELLOW, and GREEN phases automatically. At any point in the cycle, pressing a pedestrian pushbutton immediately interrupts the sequence and forces the light to RED for 8 seconds, allowing pedestrians to safely cross.

---

## Features

- Automatic RED → YELLOW → GREEN traffic light cycling
- Pedestrian button override — interrupts any phase instantly
- Non-blocking button polling during each phase (no missed presses)
- Serial Monitor logging with timestamps for each phase change
- Uses `INPUT_PULLUP` for reliable, noise-resistant button reading

---

## Hardware Requirements

| Component | Quantity |
|---|---|
| Arduino Uno (or compatible) | 1 |
| Red LED | 1 |
| Yellow LED | 1 |
| Green LED | 1 |
| 220Ω resistor | 3 |
| Pushbutton | 1 |
| Breadboard | 1 |
| Jumper wires | As needed |

---

## Circuit Diagram

```
Arduino        Component
-------        ---------

Pin 4  ──[220Ω]──► RED LED ──► GND
Pin 3  ──[220Ω]──► YELLOW LED ──► GND
Pin 2  ──[220Ω]──► GREEN LED ──► GND

Pin 7  ──────────► BUTTON ──► GND
                   (INPUT_PULLUP — no external resistor needed)
```

> **Note:** The button uses the Arduino's internal pull-up resistor (`INPUT_PULLUP`). One leg of the button connects to Pin 7 and the other directly to GND. No external resistor is required.

---

## Pin Configuration

| Arduino Pin | Role | Direction |
|---|---|---|
| 2 | Green LED | OUTPUT |
| 3 | Yellow LED | OUTPUT |
| 4 | Red LED | OUTPUT |
| 7 | Pedestrian Button | INPUT_PULLUP |

---

## How It Works

The `loop()` function cycles through three traffic light phases in order. Between each phase, `waitWithButtonCheck()` polls the button every 50 ms for the duration of that phase. If the button is detected (reads `LOW` due to `INPUT_PULLUP`), the function returns `true` and the code jumps to the `pedestrian` label, overriding the rest of the cycle.

**Normal cycle flow:**

```
RED (5s) → YELLOW (2s) → GREEN (4s) → repeat
```

**Button pressed at any point:**

```
→ RED forced ON for 8 seconds → cycle resumes normally
```

---

## Light Cycle Timing

| Phase | Duration | Trigger |
|---|---|---|
| 🔴 RED | 5 seconds | Normal cycle start |
| 🟡 YELLOW | 2 seconds | After RED |
| 🟢 GREEN | 4 seconds | After YELLOW |
| 🔴 PEDESTRIAN RED | 8 seconds | Button pressed (any phase) |

---

## Serial Monitor Output

Open the Serial Monitor at **9600 baud** to observe real-time phase changes with millisecond timestamps.

```
Traffic Light Controller Started
RED ON | Time: 1023
YELLOW ON | Time: 6045
GREEN ON | Time: 8067
PEDESTRIAN BUTTON PRESSED - RED FORCED ON | Time: 10112
RED ON | Time: 18115
...
```

---

## Getting Started

1. **Wire the circuit** according to the pin configuration and circuit diagram above.

2. **Open the sketch** in the [Arduino IDE](https://www.arduino.cc/en/software).

3. **Select your board and port:**
   - Tools → Board → Arduino Uno
   - Tools → Port → (select your COM/tty port)

4. **Upload the sketch** using the upload button (→).

5. **Open Serial Monitor** (Ctrl+Shift+M) at **9600 baud** to view live logs.

6. **Press the button** at any time to test the pedestrian override.

---

## Code Structure

```
traffic_light_controller/
│
├── traffic_light_controller.ino   # Main Arduino sketch
└── README.md                      # Project documentation
```

**Key functions:**

| Function | Description |
|---|---|
| `setup()` | Configures pin modes and starts Serial communication |
| `allOff()` | Turns off all three LEDs |
| `waitWithButtonCheck(duration)` | Waits for the given duration while polling the button every 50 ms; returns `true` if button is pressed |
| `loop()` | Runs the RED → YELLOW → GREEN cycle; jumps to pedestrian override when button is pressed |

---

## Author

**Rishu Jaiswal**

Feel free to fork, modify, and build upon this project. If you found it useful, consider leaving a ⭐ on the repository!
