#include "Wire.h"
#include "StepperDrive.h"

StepperDrive sd = StepperDrive();

void setup()
{
  //Serial.begin(9600);
  //Serial.println("Start");
  
  sd.InitHardware(0x20);
}

void loop()
{
  TestStepperDrive();
}

void TestStepperDrive()
{
  sd.SetStepPins(0,0,0,1);
  //Serial.println(sd.GetPortABits());
  sd.RefreshPortA();
  delay(1000);
  
  sd.SetStepPins(0,0,1,0);
  //Serial.println(sd.GetPortABits());
  sd.RefreshPortA();
  delay(1000);
}

