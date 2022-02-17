#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(7, 6); // RX | TX 


void send_bytes(String bytes){
  for(int i = 0; i < bytes.length(); i++){
    MyBlue.write(bytes[i]);
  }
}




void setup(){
 MyBlue.begin(9600);
} 

void loop(){
  int a, b, c;
  a = 0;
  b = 1; 
  c = 0;

  for(int i = 0; i < 30; i++){
    c = a+b;
    a = b;
    b = c;
    send_bytes("\n  ");
    send_bytes(String(c));
    delay(250);
  }
}

/*

def fib(n):
    fib0 = 0
    fib1 = 1
    f  = 0
    for i in range(n):
        if i == 1:
            continue
        f = fib0 + fib1
        fib0 = fib1
        fib1 = f
    return f
*/
