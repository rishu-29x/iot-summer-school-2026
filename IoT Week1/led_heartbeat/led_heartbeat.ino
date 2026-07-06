/*
 * Author      : Rishu Jaiswal
 * Date        : 28 June 2026
 * Description : LEDs fades 72 times per minute like real heartbeat
*/

const int ledPins[3] = {9, 10, 11}; // PWM pins connected to the 3 LEDs

const int bpm = 72;
const unsigned long beatDuration = 60000UL / bpm; // ms per beat (~833ms)

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  heartbeatPulse();
}

void heartbeatPulse() {
  unsigned long startTime = millis();
  unsigned long halfBeat = beatDuration / 2;

  // Fade IN (0 -> 255)
  while (millis() - startTime < halfBeat) {
    float progress = (float)(millis() - startTime) / halfBeat;
    int brightness = (int)(255 * progress);
    setBrightness(brightness);
  }

  unsigned long fadeOutStart = millis();
  // Fade OUT (255 -> 0)
  while (millis() - fadeOutStart < halfBeat) {
    float progress = (float)(millis() - fadeOutStart) / halfBeat;
    int brightness = 255 - (int)(255 * progress);
    setBrightness(brightness);
  }
}

void setBrightness(int value) {
  value = constrain(value, 0, 255);
  for (int i = 0; i < 3; i++) {
    analogWrite(ledPins[i], value);
  }
}
