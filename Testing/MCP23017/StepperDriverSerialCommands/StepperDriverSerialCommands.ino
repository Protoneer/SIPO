#include "Wire.h"
#include "StepperDrive.h"

StepperDrive sd = StepperDrive();

bool step_direction = false;
bool started = false;
bool old_started = true;
int speed_step_delay = 10000;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting Serial Stepper Controller");
  Serial.println("----------------------------------");
  Serial.println("S key Start/Stops");
  Serial.println("D key flips direction");
  Serial.println("+/- changes the speed");
  Serial.println("----------------------------------");

  sd.InitHardware(0x20);
}

void loop()
{
  SerialReadCommands();
  SendCommandToStepperMotor();
}

void SerialReadCommands()
{
  int incomingByte = 0; 
  
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    
    // Stop/Start
    if(incomingByte == 115 || incomingByte == 83)
    {
      started = !started;
      if(started)
      {
        Serial.println("Started");
      }
      else
      {
        Serial.println("Stopped");
      }
    }
    
    // Direction
    if(incomingByte == 100 || incomingByte == 68)
    {
      step_direction = !step_direction;
      if(step_direction)
      {
        Serial.println("Direction +");
      }
      else
      {
        Serial.println("Direction -");
      }
    }
    
    // Increase Speed
    if(incomingByte == 43)
    {
      if(speed_step_delay >= 15)
      {
        if(speed_step_delay > 200)
        {
          speed_step_delay = speed_step_delay -100; 
        }
        else
        {
          speed_step_delay = speed_step_delay -5; 
        }
        Serial.print("Currrecnt Speed(delay between steps): ");
        Serial.println(speed_step_delay);
      }
      
    }
    
    // Decrease Speed
    if(incomingByte == 45)
    {
      if(speed_step_delay <10000)
      {
        speed_step_delay = speed_step_delay +100; 
        Serial.print("Currrecnt Speed(delay between steps): ");
        Serial.println(speed_step_delay);
      }      
    }
  }
}

void SendCommandToStepperMotor()
{
  // Enable
  if(old_started != started)
  {
    sd.SetEnablePins(started,started,started,started);
    sd.RefreshPortB();
    old_started = started;
  }  
  
  // Direction
  sd.SetDirectionPins(step_direction,step_direction,step_direction,step_direction);

  // Stepping
  sd.SetStepPins(1,1,1,1);
  sd.RefreshPortA();

  delayMicroseconds(speed_step_delay);
  sd.SetStepPins(0,0,0,0);
  sd.RefreshPortA();



}


