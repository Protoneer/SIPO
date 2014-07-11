#include "Wire.h"
void setup()
{
 Wire.begin(); // wake up I2C bus
 SetPortA2Outputs();
}

void loop()
{
  byte sendByte = B00000001;
  SetPinsOnPortA(sendByte);
  delay(1000);
  SetPinsOnPortA(0);
  delay(1000);
}

void SetPortA2Outputs()
{
 Wire.beginTransmission(0x20);
 Wire.write(0x00); // IODIRA register
 Wire.write(0x00); // set all of port A to outputs
 Wire.endTransmission();
}

void SetPinsOnPortA(int a)
{
 Wire.beginTransmission(0x20);
 Wire.write(0x12); // GPIOA
 Wire.write(a); // port A
 Wire.endTransmission();
}


