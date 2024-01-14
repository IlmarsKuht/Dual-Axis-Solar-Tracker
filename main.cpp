#include <Servo.h>

Servo horizontal; 
int servoh = 180;
int servohLimitHigh = 175;
int servohLimitLow = 5;
//65 degrees max

Servo vertical;
int servov = 45;
int servovLimitHigh = 60;
int servovLimitLow = 1;

int ldrtl = A0;
int ldrtr = A3;
int ldrbl = A1;
int ldrbr = A2;

void setup()
{
  horizontal.attach(9);
  vertical.attach(10);
  horizontal.write(180);
  vertical.write(45);
  delay(2500);
}

void loop()
{
  int tl = analogRead(ldrtl);
  int tr = analogRead(ldrtr);
  int bl = analogRead(ldrbl);
  int br = analogRead(ldrbr);
  int dtime = 10; int tol = 0;
  int avt = (tl + tr) / 2;
  int avb = (bl + br) / 2;
  int avl = (tl + bl) / 2;
  int avr = (tr + br) / 2;
  int dvert = avt - avb;
  int dhoriz = avl - avr;

  if (-1*tol > dvert || dvert > tol) 
  {
    if (avt > avb)
    {
      servov = ++servov;
      if (servov > servovLimitHigh)
        servov = servovLimitHigh;
    }
    else if (avt < avb)
    {
      servov = --servov;
      if (servov < servovLimitLow)
        servov = servovLimitLow;
    }
    vertical.write(servov);
  }
  if (-1*tol > dhoriz || dhoriz > tol)
  {
    if (avl > avr)
    {
      servoh = --servoh;
      if (servoh < servohLimitLow)
      {
        servoh = servohLimitLow;
      }
    }
    else if (avl < avr)
    {
      servoh = ++servoh;
      if (servoh > servohLimitHigh)
      {
        servoh = servohLimitHigh;
      }
    }
    horizontal.write(servoh);
  }

  delay(dtime);
 
}