#include "StepperDrive.h";
#include "Wire.h"

// Used to set each bit with a bitwise or
unsigned char hex[8]= {0x01  ,0x02  ,0x04  ,0x08  ,0x10  ,0x20  ,0x40  ,0x80};

StepperDrive::StepperDrive(unsigned char I2CAddress)
{
  _portA = 0;
  _portB = 0;

  Wire.begin();
  _I2CAddress = I2CAddress;
  InitHardware();
}

void StepperDrive::InitHardware()
{
 Send(0x00,0x00);  
 Send(0x01,0x00);  
}

void StepperDrive::SetStepPins(bool pin1,bool pin2,bool pin3,bool pin4)
{
  _portA = SetBitInByte(_portA,0, pin1);
  _portA = SetBitInByte(_portA,1, pin2);
  _portA = SetBitInByte(_portA,2, pin3);
  _portA = SetBitInByte(_portA,3, pin4);
}

void StepperDrive::SetDirectionPins(bool pin1,bool pin2,bool pin3,bool pin4)
{
  _portA = SetBitInByte(_portA,4, pin1);
  _portA = SetBitInByte(_portA,5, pin2);
  _portA = SetBitInByte(_portA,6, pin3);
  _portA = SetBitInByte(_portA,7, pin4);
}
void StepperDrive::SetEnablePins(bool pin1,bool pin2,bool pin3,bool pin4)
{
  _portB = SetBitInByte(_portB,0, pin1);
  _portB = SetBitInByte(_portB,1, pin2);
  _portB = SetBitInByte(_portB,2, pin3);
  _portB = SetBitInByte(_portB,3, pin4);
}
void StepperDrive::SetGPIOPins(bool pin1,bool pin2,bool pin3,bool pin4)
{
  _portB = SetBitInByte(_portB,4, pin1);
  _portB = SetBitInByte(_portB,5, pin2);
  _portB = SetBitInByte(_portB,6, pin3);
  _portB = SetBitInByte(_portB,7, pin4);
}

void StepperDrive::SendToBoard()
{
 Send(0x12,_portA);
 Send(0x13,_portB);
}

unsigned char StepperDrive::SetBitInByte(unsigned char inByte,int bitToSet, bool bitValue)
{
  if(bitValue)
  {
    // Set the bit - or 
    return inByte|hex[bitToSet];
  }
  else
  {
    // clear the bit - and (Alos need to invert hex for & to get the bit to be set. example 11111110 instead of 00000001)
    return inByte & (~hex[bitToSet]);
  } 
}

void StepperDrive::Send(unsigned char registerAddress, unsigned char value)
{
 Wire.beginTransmission(_I2CAddress);
 Wire.write(registerAddress); // GPIOA
 Wire.write(value); // port B
 Wire.endTransmission();
}



