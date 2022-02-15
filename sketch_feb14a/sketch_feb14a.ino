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
  send_bytes("Hello World!\n");
  delay(500);
}
