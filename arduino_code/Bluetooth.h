#ifndef BLUETOOTH
#define BLUETOOTH

#include <SoftwareSerial.h>

#define RX 8 // RX pin goes to TX on HC05 module
#define TX 7 // TX pin goes to RX on HC05 module

class Bluetooth{

private:
    SoftwareSerial BluetoothSerial = SoftwareSerial(RX, TX);   // RX:7 | TX:8

public:

   Bluetooth(){
       BluetoothSerial.begin(9600);
   }
   
   void send(String val);

   void send(char val);

   void send(short val);

   void send(int val);

   void send(long val);

   void send(double val);

   void send(float val);

   String getText();

   char getChar();

};

#endif