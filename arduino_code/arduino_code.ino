
#include "Bluetooth.h"

Bluetooth bt;

void setup(){} 

void loop(){
  long a, b, c;
  a = 1;
  b = 1; 
  c = 1;

  for(int i = 0; i < 40; i++){
    c = a+b;
    a = b;
    b = c;
    bt.send("\n  ");
    bt.send(c);
    bt.send("      :  ");
    bt.send((double)b/(double)a);
    delay(100);
  }
}
