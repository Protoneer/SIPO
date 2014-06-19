#include <SPI.h>

int PinSIPOSet = 10;
// Clock =  13
// Data  = 11

// Used to set each bit with a bitwise or
unsigned char hex[8]= {0x01  ,0x02  ,0x04  ,0x08  ,0x10  ,0x20  ,0x40  ,0x80};

void setup() {                
  SPI.begin(); 
}

void loop() {
  NightRider();
  //BitCounter(1000);
  //Step(100); // Worked at 10
}

void NightRider()
{
  for(int K=0;K<8;K++)
  {
    Send2Bytes(0,0|hex[K]);
    delay(25);    
  }
  for(int K=7;K>=0;K--)
  {
    Send2Bytes(0,0|hex[K]);
    delay(25);    
  }
  
}

void Step(int delayTime){
  digitalWrite (PinSIPOSet, LOW);
  SPI.transfer(1);
  SPI.transfer(1);
  SPI.transfer(1);
  SPI.transfer(1);
  digitalWrite (PinSIPOSet,  HIGH);
  delayMicroseconds(delayTime);
  digitalWrite (PinSIPOSet, LOW);
  SPI.transfer(3);
  SPI.transfer(3);
  SPI.transfer(3);
  SPI.transfer(15);
  digitalWrite (PinSIPOSet,  HIGH);
  delayMicroseconds(delayTime);
}


void SendByte(int K)
{
  digitalWrite (PinSIPOSet, LOW);
  SPI.transfer(K);
  // if you are daisychaining, add 2nd, 3rd SPI.transfer(next_byte_of_data )
  digitalWrite (PinSIPOSet,  HIGH);
}

void Send2Bytes(int K, int K2)
{
  digitalWrite (PinSIPOSet, LOW);
  // Keep in mind that the first shifter needs to shift the data to the second shifter
  // Data needs to be sent in the correct order that is back to front
  SPI.transfer(K);
  SPI.transfer(K2);
  digitalWrite (PinSIPOSet,  HIGH);
}

void BitCounter(int waitTime){
  for(int K=0;K<256;K++)
  {
    SendByte(K);
    delay(waitTime);
  }
}
