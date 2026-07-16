/*
 * Author      : Rishu Jaiswal
 * Date        : 28 June 2026
 */

int latchPin = 10;
int clockPin = 13;
int dataPin  = 11;

void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);}

void loop(){
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, B10101010);

  digitalWrite(latchPin, HIGH);

  delay(1000);

  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, B01010101);

  digitalWrite(latchPin, HIGH);

  delay(1000);}
