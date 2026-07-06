# Traffic Light Controller with Pedestrian Override 🚦

## 📖 Project Overview

This project simulates a standard **RED → YELLOW → GREEN** traffic light cycle using three LEDs, with an added **pedestrian button override**. If the button is pressed at any point during the cycle, the light immediately switches to RED and holds there for a fixed duration, simulating a real-world pedestrian crossing signal.

## 🎯 Objective

- Implement a timed, repeating state cycle for traffic light phases
- Use `millis()`-based waiting so button presses can interrupt a phase early
- Handle an external interrupt-like condition (button press) using `goto` for phase jumping
- Log real-time system state and timestamps to the Serial Monitor

## 🛠️ Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| LEDs (Red, Yellow, Green) | 3 |
| Push Button | 1 |
| Resistors (220Ω) | 3 |
| Jumper Wires | As required |
| Breadboard | 1 |

## 🔌 Circuit Connections

| Component | Arduino Pin |
|---|---|
| Red LED | Pin 4 |
| Yellow LED | Pin 3 |
| Green LED | Pin 2 |
| Pedestrian Button | Pin 7 |

> **Note:** The button uses `INPUT_PULLUP`, so it reads **HIGH when unpressed** and **LOW when pressed** — no external resistor is needed.

## ⚙️ How It Works

1. The traffic light cycles through three phases in order: **RED (5s) → YELLOW (2s) → GREEN (4s)**, with only one LED lit at a time via the `allOff()` helper function.
2. Instead of a plain `delay()`, each phase uses `waitWithButtonCheck()`, which continuously polls the button every 50ms throughout the phase duration.
3. If the button is pressed **at any point** during a phase, `waitWithButtonCheck()` returns `true` immediately, and the program jumps straight to the `pedestrian:` label using `goto`.
4. In the pedestrian phase, all LEDs are turned off, RED is forced ON, and the light holds there for **8 seconds** before the normal cycle resumes from the top.
5. Every phase change and the pedestrian override are logged to the Serial Monitor along with the `millis()` timestamp, making it easy to trace the light's behavior over time.

## 💻 Code

The full sketch is available in [`traffic_light.ino`](./traffic_light.ino) in this folder.

## 📌 Key Concepts Learned

- Non-blocking, interruptible timing using `millis()` instead of `delay()`
- Polling an input during a wait period to react to external events mid-phase
- Using `goto` for simple state jumps (and understanding its trade-offs)
- Structuring a repeating state machine for hardware control
- Serial logging for real-time system monitoring and debugging

## 🚀 Possible Improvements

- Replace `goto` with a proper state machine (e.g., `switch`/`enum`) for cleaner, more maintainable logic
- Add a pedestrian "walk" LED or buzzer during the RED-forced phase
- Add a countdown display showing time remaining in the current phase
- Debounce the button press more robustly to avoid double-triggering on noisy signals

## ✍️ Author

**Rishu Jaiswal**
IoT Summer School 2026 — Week 2
