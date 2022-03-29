#ifndef APP
#define APP

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Bluetooth.h"
#include "JoyStick.h"

class App{

private:
    bool open = false;

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
    virtual void init(){
        open = true;
    };
    virtual void update() = 0;
    virtual void close(){
        open = false;
    }

    virtual bool is_open(){
        return open;
    }

};

#endif