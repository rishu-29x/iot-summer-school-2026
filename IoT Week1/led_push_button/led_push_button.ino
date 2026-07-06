/*
 * Author      : Rishu Jaiswal
 * Description : LED turning on and off with a switch (push button)
 */
const int buttonPin = 2;
const int ledPin = 3;

int ledState = LOW;          // LED starts off
int lastButtonState = HIGH;  // unpressed = HIGH with INPUT_PULLUP

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // button: unpressed = HIGH, pressed = LOW
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // detect the moment button goes from unpressed to pressed
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;             // flip LED state
    digitalWrite(ledPin, ledState);
    delay(200);                       // simple debounce (ignores fast double-triggers)
  }

  lastButtonState = buttonState;
}
