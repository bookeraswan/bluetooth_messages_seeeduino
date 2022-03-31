#include "../App.h"

#define MENU_APP_ID -1

class MainMenu:App{

    private:
        
        App **apps;
        int num_apps;
        int selection;
        int scroll_offset;
        int current_app;
        bool open;

    public:

        MainMenu(App **apps, int num_apps, Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App("Main Menu", display, joystick, bluetooth){
            this->apps = apps;
            this->num_apps = num_apps;
        }

        void init(){
            App::init();
            display->clearDisplay();
            display->display();
            selection = 0;
            scroll_offset = 0;
            current_app = MENU_APP_ID;
        }

        void update(){
            if(is_open()){
                display_menu();
                listen_for_selection_change();
                listen_for_click();
            }
            else{
                if(apps[current_app]->is_open()){
                    apps[current_app]->update();
                }
                else{
                    init();
                }
            }

            delay(150);
        }

        void listen_for_selection_change(){
            String command = joystick->getDirection();
            if(command == "Up" && selection > 0){
                selection--;
                if(selection < scroll_offset){
                    scroll_offset--;
                }
            }
            else if (command == "Down" && selection < num_apps-1){
                selection++;
                if(selection > scroll_offset+3){
                    scroll_offset++;
                }
            }
        }

        void listen_for_click(){
            if(joystick->pressed()){
                close();
                current_app = selection;
                apps[current_app]->init();
            }
        }

        void display_menu(){
            // top bar ---------
            display->clearDisplay();
            display->setTextSize(1);
            display->setCursor(0, 0);
            display->print(this->name);
            // app selection -----------
            display->setTextSize(1);
            display->setCursor(0, 16);
            int sp = 0;
            for(int i = scroll_offset; i < scroll_offset+4; i++){
                display->setCursor(0, 16+13*sp);
                if(selection == i) display->print("> ");
                display->print(apps[i]->name);
                sp++;
            }

            // Display To Screen
            display->display();
        }


};


