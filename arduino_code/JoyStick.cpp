#include "JoyStick.h"


String JoyStick::getDirection(){
    double theshold = 0.98;
    double x = ((double)analogRead(x_pin)/1023.0)*2.0-1; // x will be a double between -1 and 1
    double y = ((double)analogRead(y_pin)/1023.0)*2.0-1; // y will be a double between -1 and 1
    if(abs(x) < theshold && abs(y) < theshold){
      return "Center";
    }
    else if(abs(x) > abs(y)){
      if(x < 0){
        return "Right";
      }
      else{
        return "Left";
      }
    }
    else{
      if(y < 0){
        return "Up";
      }
      else{
        return "Down";
      }
    }
}

bool JoyStick::pressed(){
  return digitalRead(s_pin) == LOW;
}
