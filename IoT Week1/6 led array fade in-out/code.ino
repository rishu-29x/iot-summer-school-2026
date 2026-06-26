// Array of LEDs fading in and out one by one
// Uses PWM pins only

int ledPins[] = {3, 5, 6, 9, 10, 11};  // PWM pins
int totalLEDs = 6;                       // how many LEDs

void setup() {
  for (int i = 0; i < totalLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);         // set each pin as output
  }
}

void loop() {
  for (int i = 0; i < totalLEDs; i++) { // go through each LED

    // FADE IN
    for (int brightness = 0; brightness <= 255; brightness++) {
      analogWrite(ledPins[i], brightness);
      delay(3);
    }

    // FADE OUT
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(ledPins[i], brightness);
      delay(3);
    }

  }
}
