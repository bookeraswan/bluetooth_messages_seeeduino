#include "../App.h"



class Clock: public App{

private:

    int deci_seconds = 0;
    int seconds = 0;
    int minutes = 0;
    int hours = 0;
    bool open = false;
public:

    Clock(String name, Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App(name, display, joystick, bluetooth){

    }

    void update(){
        if(minutes == 60){
            hours++;
            minutes = 0;
        }
        if(seconds == 60){
            minutes++;
            seconds = 0;
        }
        if(deci_seconds == 10){
            seconds++;
            deci_seconds = 0;
        }
        deci_seconds++;
        display->clearDisplay();
        display->setTextSize(3);
        display->setCursor(0, 16);
        String hours_str   = hours < 10 ? "0"+String(hours) : String(hours);
        String minutes_str = minutes < 10 ? "0"+String(minutes) : String(minutes);
        String seconds_str = seconds < 10 ? "0"+String(seconds) : String(seconds);
        display->print(String(hours) + ":" + minutes_str + ":" + seconds_str);
        display->display();

        if(joystick->pressed()){
            close();
        }
    }
};