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
  send_bytes("Hey,\n");
  delay(500);
  send_bytes("I\n");
  delay(500);
  send_bytes("Think\n");
  delay(500);
  send_bytes("It's\n");
  delay(500);
  send_bytes("Crazy\n");
  delay(500);
  send_bytes("That\n");
  delay(500);
  send_bytes("This\n");
  delay(500);
  send_bytes("Is\n");
  delay(500);
  send_bytes("Possible!\n");
  delay(500);
  send_bytes(".\n");
  delay(500);
  send_bytes(".\n");
  delay(500);
  send_bytes(".\n");
  delay(500);
  send_bytes(":)\n");
  delay(1000);
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
