#include "../App.h"



class Coordinates: public App{

    public:

        Coordinates(Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App("Coordinates", display, joystick, bluetooth){

        }

        void update(){
            bluetooth->send(joystick->getDirection());
            delay(1000);
        }
};
