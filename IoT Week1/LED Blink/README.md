## Project Title

**Arduino LED Blink** — A foundational IoT project demonstrating digital output control by blinking the built-in LED on Arduino Uno every second.

----------------------------------------

## Hardware Required

| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| LED (Red) | 1 |
| Resistor (220Ω) | 1 |
| Breadboard | 1 |
| Jumper Wires | 2 |
| USB Cable (Type-B) | 1 |

----------------------------------------

## Circuit Diagram Description

The circuit is built as follows:
- Connect the **positive leg (anode)** of the LED to **Pin 13** on the Arduino
- Connect a **220Ω resistor** in series between Pin 13 and the LED anode
- Connect the **negative leg (cathode)** of the LED to **GND** on the Arduino
- The resistor protects the LED from excess current

----------------------------------------

## How to Upload Code

Follow these steps to upload the code to your Arduino:

1. Install **Arduino IDE** from https://www.arduino.cc/en/software
2. Connect Arduino Uno to your computer using a **USB cable**
3. Open Arduino IDE → click **File** → **Open** → select `code.ino`
4. Go to **Tools** → **Board** → select **Arduino Uno**
5. Go to **Tools** → **Port** → select the correct COM port
6. Click the **Upload button** (right arrow icon)
7. Wait for "Done uploading" message at the bottom
8. The LED on Pin 13 should start blinking every second

----------------------------------------

## Expected Output

- The LED turns **ON** for 1 second
- The LED turns **OFF** for 1 second
- This cycle repeats **indefinitely**
- Serial Monitor (9600 baud) shows:
- LED Blink Program v1.3 Started

Blink #1 - LED ON

LED OFF

Blink #2 - LED ON

LED OFF

----------------------------------------

## Troubleshooting Tips

1. **LED not blinking** — Check that the LED legs are correctly oriented (longer leg = anode = Pin 13)
2. **Upload error** — Make sure the correct COM port is selected under Tools → Port
3. **LED very dim** — Replace the 220Ω resistor; it may have too high a resistance value
4. **"Port not found" error** — Try a different USB cable or USB port on your computer
5. **Board not detected** — Reinstall the Arduino USB driver or restart Arduino IDE
