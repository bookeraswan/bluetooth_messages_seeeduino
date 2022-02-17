#include "Bluetooth.h"


void Bluetooth::send(String val){
    for(int i = 0; i < val.length(); i++){
        this->send(val[i]);
    }
}

void Bluetooth::send(char val){
    this->BluetoothSerial.write(val);
}

void Bluetooth::send(short val){
    this->send(String(val));
}

void Bluetooth::send(int val){
    this->send(String(val));
}

void Bluetooth::send(long val){
  this->send(String(val));
}

void Bluetooth::send(double val){
    this->send(String(val));
}

void Bluetooth::send(float val){
    this->send(String(val));
}
