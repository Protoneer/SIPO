#include <SPI.h>

void setup() {                
  SPI.begin(); 
}

void loop() {
  for(int K=0;K<256;K++)
  {
    digitalWrite (10, LOW);
    SPI.transfer(K);
    // if you are daisychaining, add 2nd, 3rd SPI.transfer(next_byte_of_data )
    digitalWrite (10,  HIGH);
    delay(200);
  }
}
