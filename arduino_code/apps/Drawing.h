#include "../App.h"
#include "../Vec.h"


#define WIDTH 128
#define HEIGHT 64


class Drawing: public App{

    private:
        Vec curser = Vec(WIDTH/2, HEIGHT/2);
    public:

        Drawing(Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App("Drawing", display, joystick, bluetooth){
            
        }

        void update(){
            display->clearDisplay();
            drawCurser();
            display->display();
        }

        void drawCurser(){
            for(int i = 0; i < 5; i++){
                display->drawPixel(curser.getX(), curser.getY()+i, WHITE);
                display->drawPixel(curser.getX(), curser.getY()-i, WHITE);

                display->drawPixel(curser.getX()+i, curser.getY(), WHITE);
                display->drawPixel(curser.getX()-i, curser.getY(), WHITE);
            }
        }


        void reset(){

        }


        void clickedButton(){

        };

        void movedUp(){
            curser.setY(curser.getY()-1);
        };

        void movedDown(){
            curser.setY(curser.getY()+1);
        };

        void movedRight(){
            curser.setX(curser.getX()+1);
        };

        void movedLeft(){
            curser.setX(curser.getX()-1);
        };
};