/*
Sam Boyen s16729 sameno20
Darrell Morel s174512 Darrell-M 
Asman Ali 
1IOT_D1
*/

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> 

int X_PIN = 34;
int Y_PIN = 35;
int SW_PIN = 32;

int X = 0;
int Y = 0;
int M1_S = 0;
int M2_S = 0;
int R = 0; 

int M1_IA = 18;
int M1_IB = 5;
int M2_IA = 2; 
int M2_IB = 15;
LiquidCrystal_I2C lcd(0x27,16,2);


void setup(){
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");

	pinMode(M1_IA,OUTPUT);
	pinMode(M1_IB,OUTPUT);
  pinMode(M2_IA,OUTPUT);
  pinMode(M2_IB,OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop(){
  X = map(analogRead(X_PIN), 0, 4095, -255, 255);
  Y = map(analogRead(Y_PIN), 0, 4095, -255, 255);
  
  if(X >= 10){
    M1_S = X;
    M2_S = X;
    R = 0;
  }
  else if(X <= -10){
    M1_S = abs(X);
    M2_S = abs(X);
    R = 1;
  }
  else{
    M1_S = 0;
    M2_S = 0;
  }

  if(Y >= 10 or Y <= -10){
    M1_S = M1_S + Y;
    M2_S = M2_S - Y;

    if(M1_S > 255){
      M1_S = 255;
    }
    if(M1_S < 0){
      M1_S = 0;
    }
    if(M2_S > 255){
      M2_S = 255;
    }
    if(M2_S < 0){
      M2_S = 0;
    }
  }
  
  Serial.println(M1_S);
  Serial.println(M2_S);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(M1_S);
  lcd.setCursor(0,1);
  lcd.print(M2_S);

  if(R == 0){
    analogWrite(M1_IA, M1_S);
    analogWrite(M1_IB, 0);
    analogWrite(M2_IA, M2_S);
    analogWrite(M2_IB, 0);
  }
  else if(R == 1){
    analogWrite(M1_IB, M1_S);
    analogWrite(M1_IA, 0);
    analogWrite(M2_IB, M2_S);
    analogWrite(M2_IA, 0);
  }
  delay(100);
}