# 🗓️ IoT Week 1

**Arduino Fundamentals — Digital I/O, PWM, Timing & Randomness**

![Arduino](https://img.shields.io/badge/Platform-Arduino_UNO-00979D?style=flat-square&logo=arduino&logoColor=white)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=flat-square)
![Program](https://img.shields.io/badge/IoT_Summer_School-2026-blueviolet?style=flat-square)

## 📌 About This Week

Week 1 focused on building a strong foundation in embedded systems using the Arduino UNO — covering digital and analog I/O, PWM-based brightness control, LED multiplexing, timing logic, and basic randomness. Each project below has its own folder with source code, a circuit diagram, and a detailed README.

## 📖 Projects

| # | Project | Core Concept | Folder |
|---|---|---|---|
| 1 | 4x4 LED Matrix | Multiplexing & character display | [`4x4 Led Matrix`](./4x4%20Led%20Matrix) |
| 2 | 6 LED Array Fade In-Out | PWM brightness control | [`6 led array fade in-out`](./6%20led%20array%20fade%20in-out) |
| 3 | 7 LED Dice | Randomness & animation | [`7_led_dice`](./7_led_dice) |
| 4 | LED Blink — Potentiometer Control | Analog input & mapping | [`LED Blink`](./LED%20Blink) |
| 5 | Heartbeat LED Pulse | Non-blocking timing | [`led_heartbeat`](./led_heartbeat) |
| 6 | Push Button LED Toggle | Digital input & edge detection | [`led_push_button`](./led_push_button) |

---

### 🔢 1. 4x4 LED Matrix
Displays custom characters on a 4x4 LED grid using row-column multiplexing — LEDs are scanned so fast the human eye sees a stable image. Cycles through letters and a smiley face automatically.

- **Folder:** [`4x4 Led Matrix`](./4x4%20Led%20Matrix)
- **Tinkercad:** *[Paste link here]*

### 💡 2. 6 LED Array Fade In-Out
Six LEDs fade smoothly in and out one after another using `analogWrite()`, creating a flowing wave-like light effect across the array.

- **Folder:** [`6 led array fade in-out`](./6%20led%20array%20fade%20in-out)
- **Tinkercad:** *[Paste link here]*

### 🎲 3. 7 LED Dice
A fully working electronic dice — press a button to trigger a spinning animation across 7 LEDs in a classic dice-dot layout, gradually slowing down before landing on a random result.

- **Folder:** [`7_led_dice`](./7_led_dice)
- **Tinkercad:** *[Paste link here]*

### 🔆 4. LED Blink — Potentiometer Control
An LED blinks at a speed controlled live by a potentiometer. Blink count and current speed are logged in real time to the Serial Monitor.

- **Folder:** [`LED Blink`](./LED%20Blink)
- **Tinkercad:** *[Paste link here]*

### ❤️ 5. Heartbeat LED Pulse
Three LEDs pulse together in sync to mimic a realistic heartbeat at 72 BPM, using `millis()` for precise, non-blocking fade timing.

- **Folder:** [`led_heartbeat`](./led_heartbeat)
- **Tinkercad:** *[Paste link here]*

### 🔘 6. Push Button LED Toggle
Pressing a push button toggles an LED on and off, rather than lighting it only while held. Uses `INPUT_PULLUP` with simple debounce logic for reliable single-press detection.

- **Folder:** [`led_push_button`](./led_push_button)
- **Tinkercad:** *[Paste link here]*

---

## 🧠 Skills & Concepts Covered

`Digital I/O` · `Analog I/O` · `PWM` · `LED Multiplexing` · `Randomness` · `Edge Detection` · `Debouncing` · `millis() Timing` · `Serial Communication`

---

## ✍️ Author

**Rishu Jaiswal**
IoT Summer School 2026 — Week 1
