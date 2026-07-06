# LED Array — Sequential Fade In/Out ✨

## 📖 Project Overview

This project controls an array of **6 LEDs** connected to PWM-capable pins, making each one smoothly fade in and fade out in sequence. Instead of a simple on/off blink, `analogWrite()` is used to gradually vary brightness, creating a smooth breathing-light effect that moves across the LED array one at a time.

## 🎯 Objective

- Understand PWM (Pulse Width Modulation) and how it simulates variable brightness
- Control multiple LEDs using arrays and loops instead of repetitive code
- Implement smooth fade transitions using `analogWrite()`
- Practice iterating over pin arrays with `for` loops

## 🛠️ Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| LEDs | 6 |
| Resistors (220Ω) | 6 |
| Jumper Wires | As required |
| Breadboard | 1 |

## 🔌 Circuit Connections

| LED | Arduino Pin (PWM) |
|---|---|
| LED 1 | Pin 3 |
| LED 2 | Pin 5 |
| LED 3 | Pin 6 |
| LED 4 | Pin 9 |
| LED 5 | Pin 10 |
| LED 6 | Pin 11 |

> **Note:** All pins used are PWM-capable (marked with `~` on the Arduino UNO), since `analogWrite()` only works on these pins.

## ⚙️ How It Works

1. All six LED pins are stored in an array (`ledPins[]`) and set as `OUTPUT` in `setup()`.
2. In `loop()`, the code cycles through each LED one at a time:
   - **Fade In:** Brightness is increased from 0 to 255 in small steps, with a short 3ms delay between steps, using `analogWrite()`.
   - **Fade Out:** Brightness is then decreased from 255 back to 0 the same way.
3. Once one LED completes its fade in/out cycle, the loop moves to the next LED, creating a moving wave-like lighting effect across the array.

## 💻 Code

The full sketch is available in [`led_array_fade.ino`](./led_array_fade.ino) in this folder.

## 📌 Key Concepts Learned

- PWM signal generation using `analogWrite()`
- Simulating analog brightness control on digital pins
- Using arrays to manage multiple components efficiently
- Nested loops for creating fade transitions
- Sequential control logic for multi-LED effects

## 🚀 Possible Improvements

- Run multiple LEDs fading simultaneously instead of one at a time
- Adjust fade speed using a potentiometer
- Add a reverse-direction fade pattern (ping-pong effect)
- Convert to non-blocking timing using `millis()` for smoother multitasking

## ✍️ Author

**Rishu Jaiswal**
IoT Summer School 2026 — Week 1
