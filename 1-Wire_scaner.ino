#include <OneWire.h>
OneWire  ds(10); 

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  byte i;
  byte addr[8];
 
  if ( !ds.search(addr)) {
    ds.reset_search();
    delay(1000);
    return;
  }

  if (OneWire::crc8( addr, 7) != addr[7]) { 
      Serial.print("CRC is not valid!\n");
      return; 
  }

   Serial.print("address:");
  for( i = 0; i < 8; i++) {
    Serial.write(' ');
    if ( addr[i]<16) {
      Serial.print("0");
    }
    Serial.print(addr[i], HEX);
  }
 
  Serial.println();

}
