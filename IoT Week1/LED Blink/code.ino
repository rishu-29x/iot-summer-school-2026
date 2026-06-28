int ledPin = 13;
int blinkCount = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(A0);
  int blinkSpeed = map(potValue, 0, 1023, 100, 1000);
  
  blinkCount++;
  digitalWrite(ledPin, HIGH);
  delay(blinkSpeed);
  digitalWrite(ledPin, LOW);
  delay(blinkSpeed);
  
  Serial.print("Blink count: ");
  Serial.print(blinkCount);
  Serial.print(" | Speed: ");
  Serial.println(blinkSpeed);
}
