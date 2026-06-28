int ledPin = 13;
int blinkCount = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  blinkCount++;
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  Serial.print("Blink count: ");
  Serial.println(blinkCount);
}
