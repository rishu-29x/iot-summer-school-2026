# LED Dice 🎲

## 📖 Project Overview

This project turns 7 LEDs into a functional **electronic dice**. Pressing a button triggers a quick spinning animation that rapidly flashes random dice faces before slowing down and settling on a final result — just like rolling a real die. Each face (1–6) is drawn using the classic dot arrangement, built from combinations of 7 LEDs positioned as corners, mid-edges, and a center dot.

## 🎯 Objective

- Represent dice face patterns as binary arrays across 7 LEDs
- Generate true randomness using `randomSeed()` seeded from an unconnected analog pin
- Create a "rolling" animation effect with progressively increasing delays
- Trigger the entire sequence from a single button press

## 🛠️ Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| LEDs | 7 |
| Push Button | 1 |
| Resistors (220Ω) | 7 |
| Jumper Wires | As required |
| Breadboard | 1 |

## 🔌 Circuit Connections

| LED Position | Arduino Pin |
|---|---|
| Top-Left (TL) | Pin 2 |
| Top-Right (TR) | Pin 3 |
| Middle-Left (ML) | Pin 4 |
| Center (C) | Pin 5 |
| Middle-Right (MR) | Pin 6 |
| Bottom-Left (BL) | Pin 7 |
| Bottom-Right (BR) | Pin 8 |
| Push Button | Pin 12 |

> **Note:** LEDs are arranged in the classic dice-dot layout (corners, center, and middle sides) so each face pattern visually resembles a real die face.

## ⚙️ How It Works

1. Each dice face (1–6) is stored as a 7-element binary pattern in the `faces[6][7]` array, mapped to the 7 LED positions.
2. `showFace()` lights up the correct combination of LEDs for a given face number by writing HIGH/LOW to each pin.
3. `randomSeed(analogRead(A0))` seeds the random number generator using electrical noise from a floating analog pin, producing a different sequence on every power-up.
4. When the button is pressed:
   - `rollAnimation()` runs a loop of 10 iterations, each showing a random face with a delay that **increases each time** (`80 + i * 20`), simulating a die that spins fast at first and gradually slows down.
   - After the animation, one final random face is chosen and displayed as the actual result.
   - A short 500ms delay prevents the button press from being registered multiple times in quick succession.

## 💻 Code

The full sketch is available in [`7_led_dice_code.ino`](./7_led_dice_code.ino) in this folder.

## 📌 Key Concepts Learned

- Representing physical objects (dice faces) as binary LED patterns
- True random number seeding using floating analog input
- Building animation effects using dynamically increasing delays
- Simple button-triggered event sequences
- Array indexing to manage multiple related LED patterns efficiently

## 🚀 Possible Improvements

- Add a second die for two-dice rolling (Yahtzee-style games)
- Add a buzzer for a rolling sound effect
- Use `INPUT_PULLUP` and proper debouncing for more reliable button detection
- Display the numeric result on Serial Monitor or an LCD alongside the LED pattern

## ✍️ Author

**Rishu Jaiswal**
IoT Summer School 2026 — Week 1
