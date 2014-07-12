
#ifndef StepperDrive_h
#define StepperDrive_h

class StepperDrive
{
public:
  void InitHardware(unsigned char I2CAddress);

  void RefreshPortA();
  void RefreshPortB();

  void SetStepPins(bool pin4,bool pin3,bool pin2,bool pin1);
  void SetDirectionPins(bool pin4,bool pin3,bool pin2,bool pin1);
  void SetEnablePins(bool pin4,bool pin3,bool pin2,bool pin1);
  void SetGPIOPins(bool pin4,bool pin3,bool pin2,bool pin1);

  unsigned char GetPortABits();
  unsigned char GetPortBBits();
  
  
private:
  unsigned char _I2CAddress;
  unsigned char _portA;
  unsigned char _portB;
  
  unsigned char SetBitInByte(unsigned char inByte,int bitToSet, bool bitValue);
  void Send(unsigned char registerAddress, unsigned char value);
};

#endif

