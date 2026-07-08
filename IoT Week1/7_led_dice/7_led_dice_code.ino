/*

- Author : Rishu Jaiswal
- Date : 29 June 2026
- Description : press the button to roll the dice and enjoy your game :)
- /
  
// LED Dice — press button to roll!
const int ledPins[7] = {2, 3, 4, 5, 6, 7, 8};
const int buttonPin = 12;

// Dice face patterns [1-6]
// LEDs: TL, TR, ML, C, MR, BL, BR
const bool faces[6][7] = {
  {0,0,0,1,0,0,0}, // 1 — center only
  {1,0,0,0,0,0,1}, // 2 — top-left, bot-right
  {1,0,0,1,0,0,1}, // 3 — + center
  {1,1,0,0,0,1,1}, // 4 — all corners
  {1,1,0,1,0,1,1}, // 5 — corners + center
  {1,1,1,0,1,1,1}  // 6 — all except center
};

void showFace(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledPins[i], faces[num][i] ? HIGH : LOW);
  }
}

void rollAnimation() {
  for (int i = 0; i < 10; i++) {
    showFace(random(0, 6));
    delay(80 + i * 20); // slows down like a real dice
  }
}

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
  randomSeed(analogRead(A0)); // true random seed
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    rollAnimation();              // spinning effect
    int result = random(0, 6);   // final result
    showFace(result);
    delay(500); // debounce
  }
}
