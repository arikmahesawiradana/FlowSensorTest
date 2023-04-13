#include <Arduino.h>

int TURBINE;
int HSensor = 14;
float Calc;

void speedrpm(){TURBINE++;}

void setup() {
  // put your setup code here, to run once:
  pinMode(HSensor, INPUT);
  Serial.begin(115200);
  attachInterrupt(00, speedrpm, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  TURBINE = 00;
  sei();
  delay(1000);
  cli();
  Calc = TURBINE * 60 / 7.5;
  Serial.print("Flow: ");
  Serial.print(Calc, DEC);
  Serial.print(" L/Hour");
}