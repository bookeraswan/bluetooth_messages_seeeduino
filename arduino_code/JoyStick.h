
#include <Arduino.h>

class JoyStick{

private:
  int x_pin;
  int y_pin;
  int s_pin;
public:

  JoyStick(int x_pin, int y_pin, int s_pin){
    this->x_pin = x_pin;
    this->y_pin = y_pin;
    this->s_pin = s_pin;
    pinMode(s_pin, INPUT_PULLUP);
  }

  String getDirection();

  bool pressed();
};
