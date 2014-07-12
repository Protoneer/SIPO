#include "Wire.h"
#include "StepperDrive.h"


// Used to set each bit with a bitwise or
//unsigned char hex[8]= {0x01  ,0x02  ,0x04  ,0x08  ,0x10  ,0x20  ,0x40  ,0x80};



void setup()
{
  Serial.begin(9600);
  Serial.println("Start");
}

void loop()
{
  TestStepperDrive();
}

void TestStepperDrive()
{
  StepperDrive sd(0x20);
  
  sd.SetStepPins(0,0,0,1);
  sd.SendToBoard();
  delay(1000);
  sd.SetStepPins(0,0,1,0);
  sd.SendToBoard();
  delay(1000);
}

