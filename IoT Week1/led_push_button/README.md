# Push Button Interfacing — LED Toggle Switch 🔘

## 📖 Project Overview

This project uses a **push button** as a toggle switch to turn an LED on and off. Instead of the LED only lighting up while the button is held down, each press flips its state — press once to turn it on, press again to turn it off. The internal pull-up resistor is used, so no external resistor is needed on the button.

## 🎯 Objective

- Use `INPUT_PULLUP` mode to read a button without an external resistor
- Detect a button **press event** (transition from unpressed to pressed) rather than a continuous held state
- Implement toggle logic to flip an LED's state on each press
- Apply basic software debouncing using `delay()`

## 🛠️ Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| Push Button | 1 |
| LED | 1 |
| Resistor (220Ω, for LED) | 1 |
| Jumper Wires | As required |
| Breadboard | 1 |

## 🔌 Circuit Connections

| Component | Arduino Pin |
|---|---|
| Push Button | Pin 2 |
| LED (Anode) | Pin 3 |
| LED (Cathode) | GND (via resistor) |
| Push Button (other terminal) | GND |

> **Note:** `INPUT_PULLUP` is used on the button pin, so it reads **HIGH when unpressed** and **LOW when pressed** — no external pull-up/pull-down resistor is required for the button itself.

## ⚙️ How It Works

1. The button pin is configured with `INPUT_PULLUP`, so its default (unpressed) state reads HIGH.
2. On every loop iteration, the current button state is compared to its previous state.
3. A toggle is triggered **only on the falling edge** — the exact moment the button goes from HIGH (unpressed) to LOW (pressed) — rather than while it's held down.
4. When this transition is detected, `ledState` is flipped using the `!` (NOT) operator, and the LED is updated accordingly.
5. A short 200ms delay after each valid press acts as a simple debounce, preventing electrical noise from the button from triggering multiple accidental toggles.
6. The last button state is saved for comparison in the next loop cycle.

## 💻 Code

The full sketch is available in [`push_button_led_toggle.ino`](./push_button_led_toggle.ino) in this folder.

## 📌 Key Concepts Learned

- Digital input reading with `INPUT_PULLUP`
- Edge detection (state-change detection) vs. simple level checking
- Toggle logic using boolean state variables
- Basic switch debouncing techniques
- Event-driven control flow in embedded programs

## 🚀 Possible Improvements

- Replace the `delay()`-based debounce with a `millis()`-based debounce for better responsiveness
- Add a second LED or buzzer for status feedback
- Use interrupts (`attachInterrupt`) for more reliable press detection
- Extend to a multi-state toggle (e.g., cycling through several LED patterns)

## ✍️ Author

**Rishu Jaiswal**
IoT Summer School 2026 — Week 1
