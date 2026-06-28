// LED Blink Program - v1.2
// Description: Added Serial Monitor feedback

const int LED_PIN = 13;
const int BLINK_DELAY = 1000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("LED Blink Program v1.2 Started");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  delay(BLINK_DELAY);

  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  delay(BLINK_DELAY);
}
