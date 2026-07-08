/*
=========================================================
Project      : Blink Modified
File         : blink_modified.ino
Author       : P Meet Kumar
Roll Number  : IoT 009
Program      : IoT and Drone Building Summer School 2026
Institution  : Indian Institute of Technology Jammu (IIT Jammu)

Description:
This program blinks an LED three times rapidly and then
pauses for two seconds before repeating continuously.
=========================================================
*/

const int Pin = 9;   // LED connected to Digital Pin 9

void setup() {
  pinMode(Pin, OUTPUT);
}

void loop() {

  // Blink the LED 3 times quickly
  for (int i = 1; i <= 3; i++) {

    digitalWrite(Pin, HIGH);
    delay(200);

    digitalWrite(Pin, LOW);
    delay(200);
  }

  // Pause for 2 seconds
  delay(2000);
}
