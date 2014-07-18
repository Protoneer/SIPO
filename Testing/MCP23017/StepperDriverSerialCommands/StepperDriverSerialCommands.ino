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
  sd.SetStepPins(1,1,1,1);
  sd.SetDirectionPins(1,1,1,1);
  sd.SetEnablePins(0,0,0,0);
  sd.SetGPIOPins(1,1,1,1);
  //Serial.println(sd.GetPortABits());
  sd.RefreshPortA();
  sd.RefreshPortB();
  delay(50);
  
  sd.SetStepPins(0,0,0,0);
  sd.SetDirectionPins(0,0,0,0);
  sd.SetEnablePins(1,1,1,1);
  sd.SetGPIOPins(0,0,0,0);
  //Serial.println(sd.GetPortABits());
  sd.RefreshPortA();
  sd.RefreshPortB();
  delay(50);
}

