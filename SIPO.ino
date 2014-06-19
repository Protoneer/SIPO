#include <SPI.h>

int PinSIPOSet = 10;
// Clock =  13
// Data  = 11

void setup() {                
  SPI.begin(); 
}

void loop() {
  //BitCounter(1000);
  Step(100); // Worked at 10
  //delayMicroseconds(250);
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
  SPI.transfer(3);
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
  // Keep in mind that the first shifter needs to shif the data to the second shifter
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
