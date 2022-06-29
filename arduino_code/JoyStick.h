#ifndef JOYSTICK
#define JOYSTICK

#include <Arduino.h>
#include "Vec.h"

#define CENTER 'C'
#define RIGHT 'R'
#define LEFT 'L'
#define UP 'U'
#define DOWN 'D'

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

  char getDirection();

  Vec getMovement();

  bool pressed();
};

#endif