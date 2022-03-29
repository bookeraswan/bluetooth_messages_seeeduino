#include "../App.h"


class VsCode : public App{
    
    public:

        VsCode(String name, Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App(name, display, joystick, bluetooth){

        }

        void update(){
            bluetooth->send('v');
            close();
        }

};