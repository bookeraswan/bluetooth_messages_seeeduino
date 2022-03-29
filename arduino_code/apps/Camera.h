#include "../App.h"


class Camera : public App{
    
    public:

        Camera(String name, Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App(name, display, joystick, bluetooth){

        }

        void update(){
            bluetooth->send('c');
            close();
        }

};