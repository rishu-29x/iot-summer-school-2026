// LED Blink Program - v1.1
// Description: Basic LED blink with named constants and comments

const int LED_PIN = 13;      // Built-in LED pin on Arduino Uno
const int BLINK_DELAY = 1000; // Delay in milliseconds

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // Turn LED ON
  delay(BLINK_DELAY);
  digitalWrite(LED_PIN, LOW);   // Turn LED OFF
  delay(BLINK_DELAY);
}
