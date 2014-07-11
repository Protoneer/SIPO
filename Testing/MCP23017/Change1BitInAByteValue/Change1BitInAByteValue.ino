// Used to set each bit with a bitwise or
unsigned char hex[8]= {0x01  ,0x02  ,0x04  ,0x08  ,0x10  ,0x20  ,0x40  ,0x80};

#include "Wire.h"
void setup()
{
 Wire.begin(); // wake up I2C bus
 SetPortA2Outputs();
}

void loop()
{
  byte sendByte = B11111111;
  SetPinsOnPortA(SetBitInByte(sendByte,0,0));
  delay(1000);
  SetPinsOnPortA(sendByte);
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

byte SetBitInByte(byte inByte,int bitToSet, bool bitValue)
{
  if(bitValue)
  {
    // Set the bit - or 
    return inByte|hex[bitToSet];
  }
  else
  {
    // clear the bit - and (Alos need to invert hex for & to get the bit to be set. example 11111110 instead of 00000001)
    return inByte & InvertByte(hex[bitToSet]);
  } 
}

byte InvertByte(byte inByte)
{
  return ~inByte;
}


