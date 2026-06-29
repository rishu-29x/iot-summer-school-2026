# 🎹 Digital Piano using Buzzer

An Arduino-based digital piano that plays musical notes through a buzzer using 4 buttons, with support for **Major and Minor scale toggling** and a **chord substitute** when two buttons are pressed simultaneously.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Circuit Diagram](#circuit-diagram)
- [Pin Configuration](#pin-configuration)
- [How It Works](#how-it-works)
- [Note & Frequency Reference](#note--frequency-reference)
- [Serial Monitor Output](#serial-monitor-output)
- [Getting Started](#getting-started)
- [Code Structure](#code-structure)
- [Author](#author)

---

## Overview

This project turns an Arduino into a mini digital piano. Four buttons correspond to the musical notes Do, Re, Mi, and Fa. A fifth button toggles between the Major and Minor scale, changing the frequencies played by Re and Mi. Pressing any two note buttons at the same time plays Sol (392 Hz) as a chord substitute.

---

## Features

- 4 buttons play **Do, Re, Mi, Fa** on a piezo buzzer
- Buzzer **silences immediately** on button release — no lingering tone
- Pressing **any two buttons together** plays **Sol** (chord substitute at 392 Hz)
- 5th button **toggles between Major and Minor** scale in real time
- Scale toggle is **debounced** — fires only once per press
- **Serial Monitor** logs every note played and every mode switch

---

## Hardware Requirements

| Component | Quantity |
|---|---|
| Arduino Uno (or compatible) | 1 |
| Piezo buzzer | 1 |
| Pushbutton | 5 |
| 10kΩ resistor (pull-down) | 5 |
| Breadboard | 1 |
| Jumper wires | As needed |

---

## Circuit Diagram

```
Arduino        Component
-------        ---------

Pin 2  ──────────► BTN1 (Do)   ── VCC
                   [10kΩ to GND]

Pin 3  ──────────► BTN2 (Re)   ── VCC
                   [10kΩ to GND]

Pin 4  ──────────► BTN3 (Mi)   ── VCC
                   [10kΩ to GND]

Pin 5  ──────────► BTN4 (Fa)   ── VCC
                   [10kΩ to GND]

Pin 6  ──────────► BTN_MODE    ── VCC
                   [10kΩ to GND]

Pin 9  ──────────► Buzzer (+)
GND    ──────────► Buzzer (-)
```

> **Note:** Buttons are wired with external **10kΩ pull-down resistors** (`INPUT` mode). The pin reads `HIGH` when a button is pressed and `LOW` when released.

---

## Pin Configuration

| Arduino Pin | Role | Direction |
|---|---|---|
| 2 | Button 1 — Do | INPUT |
| 3 | Button 2 — Re | INPUT |
| 4 | Button 3 — Mi | INPUT |
| 5 | Button 4 — Fa | INPUT |
| 6 | Mode Toggle Button | INPUT |
| 9 | Piezo Buzzer | OUTPUT |

---

## How It Works

On every `loop()` iteration, all five buttons are read simultaneously.

**Note priority logic:**
- If **2 or more** note buttons are pressed → play **Sol (392 Hz)**
- If exactly **1** note button is pressed → play its corresponding note from the active scale
- If **no** button is pressed → `noTone()` silences the buzzer

**Mode toggle:**
The mode button uses edge detection — it only switches scale when it transitions from `LOW` to `HIGH` (i.e., on press, not hold), with a 200 ms software debounce.

```
Major mode:  Do=262Hz  Re=294Hz  Mi=330Hz  Fa=349Hz
Minor mode:  Do=262Hz  Re=277Hz  Mi=311Hz  Fa=349Hz
```

Do and Fa remain the same in both scales. Re and Mi shift down a semitone in Minor mode.

---

## Note & Frequency Reference

| Button | Note | Major (Hz) | Minor (Hz) |
|---|---|---|---|
| BTN1 | Do | 262 | 262 |
| BTN2 | Re | 294 | 277 (Re♭) |
| BTN3 | Mi | 330 | 311 (Mi♭) |
| BTN4 | Fa | 349 | 349 |
| BTN1 + any | Sol (chord) | 392 | 392 |

---

## Serial Monitor Output

Open the Serial Monitor at **9600 baud** to see real-time note and mode logs.

```
=== Digital Piano Ready ===
Current Mode: Major
Playing Do: 262
Playing Re: 294
Playing Mi: 330
Chord: Sol (392Hz)
Mode switched to: Minor
Playing Re: 277
Playing Mi: 311
```

---

## Getting Started

1. **Wire the circuit** according to the pin configuration and circuit diagram above.

2. **Open the sketch** in the [Arduino IDE](https://www.arduino.cc/en/software).

3. **Select your board and port:**
   - Tools → Board → Arduino Uno
   - Tools → Port → (select your COM/tty port)

4. **Upload the sketch** using the upload button (→).

5. **Open Serial Monitor** (Ctrl+Shift+M) at **9600 baud**.

6. **Press the buttons** to play notes. Press two at once for a chord. Use BTN_MODE to switch scales.

---

## Code Structure

```
digital_piano/
│
├── digital_piano.ino   # Main Arduino sketch
└── README.md           # Project documentation
```

**Key variables and logic:**

| Element | Description |
|---|---|
| `majorFreqs[4]` | Frequency array for Do, Re, Mi, Fa in Major scale |
| `minorFreqs[4]` | Frequency array for Do, Re, Mi, Fa in Minor scale |
| `isMajor` | Boolean flag tracking current active scale |
| `lastModeState` | Stores previous mode button state for edge detection |
| `pressedCount` | Sum of all note button states; ≥2 triggers Sol chord |
| `tone(pin, freq)` | Arduino built-in to play a frequency on the buzzer |
| `noTone(pin)` | Arduino built-in to silence the buzzer |

---

## Author

**Rishu Jaiswal**

Feel free to fork, modify, and build upon this project. If you found it useful, consider leaving a ⭐ on the repository!
