# Heartbeat LED Pulse ❤️

## 📖 Project Overview

This project makes a set of **3 LEDs fade in and out in sync**, mimicking a realistic heartbeat rhythm at **72 beats per minute (BPM)** — the average human resting heart rate. Each "beat" consists of a smooth fade-in followed by a smooth fade-out, timed precisely using `millis()` for accurate, non-blocking pacing.

## 🎯 Objective

- Calculate real-world timing (BPM) and convert it into millisecond-based delays
- Implement smooth brightness transitions using `analogWrite()` and floating-point progress ratios
- Use `millis()`-based timing instead of `delay()` for more precise, controllable pulsing
- Control multiple LEDs simultaneously as a single synchronized group

## 🛠️ Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| LEDs | 3 |
| Resistors (220Ω) | 3 |
| Jumper Wires | As required |
| Breadboard | 1 |

## 🔌 Circuit Connections

| LED | Arduino Pin (PWM) |
|---|---|
| LED 1 | Pin 9 |
| LED 2 | Pin 10 |
| LED 3 | Pin 11 |

> **Note:** All three LEDs share the same brightness value at all times, so they pulse together as one synchronized "heartbeat."

## ⚙️ How It Works

1. The desired heart rate (**72 BPM**) is converted into a beat duration in milliseconds:
   `beatDuration = 60000 / bpm` → approximately **833ms per full beat**.
2. Each beat is split into two equal halves — fade-in and fade-out — each lasting `beatDuration / 2`.
3. During **fade-in**, the elapsed time since the beat started is used to calculate a progress ratio (0.0 to 1.0), which is scaled to a brightness value from 0 to 255.
4. During **fade-out**, the same logic runs in reverse, taking brightness from 255 back down to 0.
5. The `setBrightness()` function applies this value to all three LEDs simultaneously using `analogWrite()`, with `constrain()` ensuring the value always stays within the valid 0–255 range.
6. This cycle repeats continuously in `loop()`, producing a steady, rhythmic pulsing effect.

## 💻 Code

The full sketch is available in [`heartbeat_led_pulse.ino`](./led_heartbeat.ino) in this folder.

## 📌 Key Concepts Learned

- Converting real-world units (BPM) into program timing values
- Non-blocking timing using `millis()` instead of `delay()`
- Smooth brightness interpolation using progress ratios
- Synchronizing multiple outputs to behave as one unit
- Using `constrain()` to safely bound calculated values

## 🚀 Possible Improvements

- Make BPM adjustable via a potentiometer for a "live heart rate" simulation
- Add a buzzer for an audible heartbeat sound alongside the LED pulse
- Introduce a more realistic "lub-dub" double-pulse pattern per beat
- Read live BPM from a pulse sensor for a real biometric-linked display

## ✍️ Author

**Rishu Jaiswal**
IoT Summer School 2026 — Week 1
