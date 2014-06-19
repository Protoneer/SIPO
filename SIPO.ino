#include <SPI.h>

int PinSIPOSet = 10;
// Clock =  13
// Data  = 11

// Used to set each bit with a bitwise or
unsigned char hex[8]= {0x01  ,0x02  ,0x04  ,0x08  ,0x10  ,0x20  ,0x40  ,0x80};

/*

P4
P3
P2
P1
4DIR
4STEP
4EN
3DIR
3STEP
3EN
2DIR
2STEP
2EN
1DIR
1STEP
1EN

*/

typedef struct {
  boolean P[4]; // Output Pins  
  boolean EN[4];       // Enable Pins  
  boolean STEP[4];     // Step Pins  
  boolean DIR[4];      // Direction Pins
} sipo_t;

sipo_t SIPO;

void SendSIPO()
{
    // Populate SIPO
  for(int K=0;K<4;K++)
  {
    SIPO.P[K] = 1;
  }

  
  int byte1 = 0;
  int byte2 = 0;

  if(SIPO.P[0]) byte2 = byte2 | hex[8-1];
  if(SIPO.P[1]) byte2 = byte2 | hex[7-1];
  if(SIPO.P[2]) byte2 = byte2 | hex[6-1];
  if(SIPO.P[3]) byte2 = byte2 | hex[5-1];

  Send2Bytes(0,byte2);
 
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


void setup() {                
  SPI.begin(); 
}

void loop() {

  //SendSIPO();
  NightRider();
  //BitCounter(1000);
  //Step(100); // Worked at 10
}

