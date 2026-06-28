/*
 Q15: Digital Piano using Buzzer
 
 */

const int BTN1 = 2;  // Do
const int BTN2 = 3;  // Re
const int BTN3 = 4;  // Mi
const int BTN4 = 5;  // Fa
const int BUZZER = 9;

void setup() {
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);
  pinMode(BTN4, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  bool b1 = digitalRead(BTN1);
  bool b2 = digitalRead(BTN2);
  bool b3 = digitalRead(BTN3);
  bool b4 = digitalRead(BTN4);

  if (b1) {
    tone(BUZZER, 262);  // Do
  }
  else if (b2) {
    tone(BUZZER, 294);  // Re
  }
  else if (b3) {
    tone(BUZZER, 330);  // Mi
  }
  else if (b4) {
    tone(BUZZER, 349);  // Fa
  }
  else {
    noTone(BUZZER);     // silence when no button pressed
  }

  delay(10);
}
