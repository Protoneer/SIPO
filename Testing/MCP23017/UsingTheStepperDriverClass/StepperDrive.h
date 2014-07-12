
#ifndef StepperDrive_h
#define StepperDrive_h

class StepperDrive
{
public:
  StepperDrive(unsigned char I2CAddress);
  void SendToBoard();
  
  
  
  

  // SendCurrentSettings
  // Set the 4 parts of the driver

  void SetStepPins(bool pin1,bool pin2,bool pin3,bool pin4);
  void SetDirectionPins(bool pin1,bool pin2,bool pin3,bool pin4);
  void SetEnablePins(bool pin1,bool pin2,bool pin3,bool pin4);
  void SetGPIOPins(bool pin1,bool pin2,bool pin3,bool pin4);
  
  
private:
  unsigned char _I2CAddress;
  unsigned char _portA;
  unsigned char _portB;
  
  void InitHardware();
  unsigned char SetBitInByte(unsigned char inByte,int bitToSet, bool bitValue);
  void Send(unsigned char registerAddress, unsigned char value);
};

#endif

