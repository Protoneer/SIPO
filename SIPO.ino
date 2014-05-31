#include <SPI.h>

int PinSIPOSet = 10;

void setup() {                
  SPI.begin(); 
}

void loop() {
  //BitCounter(5);
  //SendByte(1);
  Send2Bytes(2,1);
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
