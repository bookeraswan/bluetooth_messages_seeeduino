#include "../App.h"


class MainMenu:App{

    private:
        
        
    public:

        MainMenu(Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App("MainMenu", display, joystick, bluetooth){

        }

        void init(){}

        void update(){

        }

        void close(){}

        bool is_open(){}


        void display_screen(){}
};


