# Digital Piano using Buzzer 🎹

## 📖 Project Overview

This project turns a simple **piezo buzzer** into a 4-note digital piano. Four push buttons play the notes **Do, Re, Mi, and Fa**, releasing a button silences that note, and pressing two buttons together plays **Sol** as a chord substitute. A fifth button toggles the piano between **Major** and **Minor** scale modes, changing the pitch of Re and Mi. All activity is logged to the Serial Monitor for easy debugging and observation.

## 🎯 Objective

- Generate different musical tones using `tone()` and `noTone()`
- Read multiple button inputs simultaneously to detect single presses and combinations
- Implement a toggle mode using edge detection and debouncing
- Use arrays and pointers to switch between two sets of frequency values dynamically

## 🛠️ Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| Push Buttons | 5 |
| Piezo Buzzer | 1 |
| Jumper Wires | As required |
| Breadboard | 1 |

## 🔌 Circuit Connections

| Component | Arduino Pin | Function |
|---|---|---|
| Button 1 | Pin 2 | Do |
| Button 2 | Pin 3 | Re |
| Button 3 | Pin 4 | Mi |
| Button 4 | Pin 5 | Fa |
| Mode Button | Pin 6 | Major/Minor Toggle |
| Buzzer (+) | Pin 9 | Tone Output |
| Buzzer (−) | GND | Ground |

## ⚙️ How It Works

1. Two frequency arrays are defined — `majorFreqs[]` and `minorFreqs[]` — holding the pitch values (in Hz) for Do, Re, Mi, and Fa in each scale.
2. A `bool isMajor` flag tracks the current scale mode, starting in **Major**.
3. The mode button is checked for a rising-edge press (transition from unpressed to pressed) to flip `isMajor`, with a 200ms delay used as a simple debounce so one press doesn't register multiple toggles.
4. Based on `isMajor`, a pointer (`freqs`) is set to point to the correct frequency array for that mode.
5. All four note buttons are read every loop cycle:
   - If **two or more** buttons are pressed at once, the buzzer plays a fixed **Sol (392Hz)** tone as a chord substitute.
   - If exactly **one** button is pressed, its corresponding note is played from the currently active scale.
   - If **no** button is pressed, `noTone()` silences the buzzer.
6. Serial Monitor messages confirm the current mode and which note or chord is playing at any given moment.

## 💻 Code

The full sketch is available in [`digital_piano.ino`](./digital_piano.ino) in this folder.

## 📌 Key Concepts Learned

- Tone generation with `tone()` and `noTone()`
- Reading and combining multiple simultaneous digital inputs
- Edge detection for reliable single-trigger toggle switches
- Using pointers to switch between different data arrays at runtime
- Real-time Serial logging for debugging interactive input systems

## 🚀 Possible Improvements

- Add more notes/octaves using additional buttons
- Replace basic delay-based debounce with a more robust `millis()`-based approach
- Add a proper chord table instead of a single fixed Sol substitute
- Use an LCD to visually display the current note and mode instead of only Serial output

## ✍️ Author

**Rishu Jaiswal**
IoT Summer School 2026 — Week 2
