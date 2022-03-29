#include "../App.h"


class Chrome : public App{

    public:

        Chrome(String name, Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App(name, display, joystick, bluetooth){

        }

        void update(){
            bluetooth->send('g');
            close();
        }

};