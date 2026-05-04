/*
Sam Boyen s16729
1IOT_D1
*/

#include <Arduino.h>

int Vooruit_knop = 23;
int Achteruit_knop = 34; 
int Links_knop = 35;
int Rechts_knop = 32;

int M1_IA = 18;
int M1_IB = 5;
int M2_IA = 2; 
int M2_IB = 15; 

int Speed_pot = 39;

int Speed_read = 0;

void setup(){
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");
	pinMode(Vooruit_knop,INPUT_PULLDOWN);
	pinMode(Achteruit_knop,INPUT_PULLDOWN);
  pinMode(Links_knop,INPUT_PULLDOWN);
  pinMode(Rechts_knop,INPUT_PULLDOWN);

	pinMode(M1_IA,OUTPUT);
	pinMode(M1_IB,OUTPUT);
  pinMode(M2_IA,OUTPUT);
  pinMode(M2_IB,OUTPUT);
}

void loop(){
  while(digitalRead(Vooruit_knop)){
    Serial.println("Vooruit");
    Speed_read = map(analogRead(Speed_pot), 0, 4095, 0, 255);
    analogWrite(M1_IA, Speed_read);
    analogWrite(M1_IB, 0);
    analogWrite(M2_IA, Speed_read);
    analogWrite(M2_IB, 0);
    delay(100);
  }
  while(digitalRead(Achteruit_knop)){
    Serial.println("Achteruit");
    Speed_read = map(analogRead(Speed_pot), 0, 4095, 0, 255);
    analogWrite(M1_IB, Speed_read);
    analogWrite(M1_IA, 0);
    analogWrite(M2_IB, Speed_read);
    analogWrite(M2_IA, 0);
    delay(100);
  }
  while(digitalRead(Links_knop)){
    Serial.println("Links");
    Speed_read = map(analogRead(Speed_pot), 0, 4095, 0, 255);
    analogWrite(M1_IA, Speed_read);
    analogWrite(M1_IB, 0);
    analogWrite(M2_IB, Speed_read);
    analogWrite(M2_IA, 0);
    delay(100);
  }
  while(digitalRead(Rechts_knop)){
    Serial.println("Rechts");
    Speed_read = map(analogRead(Speed_pot), 0, 4095, 0, 255);
    analogWrite(M1_IB, Speed_read);
    analogWrite(M1_IA, 0);
    analogWrite(M2_IA, Speed_read);
    analogWrite(M2_IB, 0);
    delay(100);
  }
  analogWrite(M1_IA, 0);
  analogWrite(M1_IB, 0);
  analogWrite(M2_IA, 0);
  analogWrite(M2_IB, 0);
  delay(100);
}
  