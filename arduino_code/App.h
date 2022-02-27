#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Bluetooth.h"
#include "JoyStick.h"

class App{
public:
    String name;
    Adafruit_SSD1306 *display;
    JoyStick *joystick;
    Bluetooth *bluetooth;
    App(String name, Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth){
        this->name = name;
        this->display = display;
        this->joystick = joystick;
        this->bluetooth = bluetooth;
    }
    virtual void init()   = 0;
    virtual void update() = 0;
    virtual void close()  = 0;

};
