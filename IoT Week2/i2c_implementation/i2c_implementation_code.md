/*
 * Author      : Rishu Jaiswal
 * Date        : 30 June 2026
 */

#include<Servo.h>
float temp;

void setup(){
Serial.begin(9600);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);}

void loop(){
if(Serial.available()){
temp = Serial.parseFloat();
if(temp < 25){
digitalWrite(8, HIGH);
digitalWrite(9, LOW);
digitalWrite(10, LOW);}
else if(temp < 35){
digitalWrite(8, LOW);
digitalWrite(9, HIGH);
digitalWrite(10, LOW);}
else{
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, HIGH);}}}
