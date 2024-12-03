#include <SoftwareSerial.h>

int laser = 10;
int cds = A0;
int boo = 4;
int cdsValue;
int PIR_val = 0;
int PIR = 7;

void setup()
{
  pinMode(boo, OUTPUT);
  digitalWrite(laser, HIGH);
  pinMode(laser, OUTPUT);
  pinMode(PIR, INPUT);
  Serial.begin(9600);
}

void loop()
{
  PIR_val = digitalRead(PIR);
  cdsValue = analogRead(0);
  if (cdsValue > 220) {    
    tone(4,1000,1000);
  }

  if (PIR_val == 1)
  {
    tone(4,1000,1000);
  }
}
