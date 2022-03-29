#include "../App.h"


class Netflix : public App{

    public:

        Netflix(String name, Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App(name, display, joystick, bluetooth){

        }

        void update(){
            bluetooth->send('n');
            close();
        }

};