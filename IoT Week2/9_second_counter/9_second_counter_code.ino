/*
 * Author      : Rishu Jaiswal
 * Date        : 28 June 2026
 * Description : a simple counter that counts upto 9 seconds

 */
// 7-segment display: 0–9 second timer (Common Cathode)
// Segments: a=2, b=3, c=4, d=5, e=6, f=7, g=8

const int segPins[7] = {2, 3, 4, 5, 6, 7, 8};
//                       a  b  c  d  e  f  g

// Segment patterns for digits 0–9
// Order: a, b, c, d, e, f, g
const bool digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void displayDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], digits[num][i] ? HIGH : LOW);
  }
}

void clearDisplay() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], LOW);
  }
}

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
  clearDisplay();
}

void loop() {
  for (int i = 0; i <= 9; i++) {
    displayDigit(i);
    delay(1000); // 1 second per digit
  }
  clearDisplay();
  delay(500); // brief pause before restarting
}
