#include "../App.h"



class Coordinates: public App{

    public:

        Coordinates(Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App("Coordinates", display, joystick, bluetooth){

        }

        void init(){}

        void update(){
            bluetooth->send(joystick->getDirection());
            delay(1000);
        }

        void close(){}

        bool is_open(){
            return true;
        }
};
