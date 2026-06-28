/*
 * Traffic Light Controller
 * Author: Rishu Jaiswal
 * Description: Simulates a traffic light with pedestrian button override
 */

// Pin definitions
const int RED_PIN    = 4;
const int YELLOW_PIN = 3;
const int GREEN_PIN  = 2;
const int BUTTON_PIN = 7;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Traffic Light Controller Started");
}

void allOff() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}

// Check button during a delay — if pressed, go RED immediately
bool waitWithButtonCheck(int duration) {
  unsigned long start = millis();
  while (millis() - start < duration) {
    if (digitalRead(BUTTON_PIN) == LOW) {
      return true; // button pressed
    }
    delay(50);
  }
  return false;
}

void loop() {
  // RED phase - 5 seconds
  allOff();
  digitalWrite(RED_PIN, HIGH);
  Serial.print("RED ON | Time: ");
  Serial.println(millis());
  if (waitWithButtonCheck(5000)) goto pedestrian;

  // YELLOW phase - 2 seconds
  allOff();
  digitalWrite(YELLOW_PIN, HIGH);
  Serial.print("YELLOW ON | Time: ");
  Serial.println(millis());
  if (waitWithButtonCheck(2000)) goto pedestrian;

  // GREEN phase - 4 seconds
  allOff();
  digitalWrite(GREEN_PIN, HIGH);
  Serial.print("GREEN ON | Time: ");
  Serial.println(millis());
  if (waitWithButtonCheck(4000)) goto pedestrian;

  return;

pedestrian:
  allOff();
  digitalWrite(RED_PIN, HIGH);
  Serial.print("PEDESTRIAN BUTTON PRESSED - RED FORCED ON | Time: ");
  Serial.println(millis());
  delay(8000);
}
