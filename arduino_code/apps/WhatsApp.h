#include "../App.h"


class WhatsApp : public App{

    public:

        WhatsApp(String name, Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App(name, display, joystick, bluetooth){

        }

        void update(){
            bluetooth->send('w');
            close();
        }

};