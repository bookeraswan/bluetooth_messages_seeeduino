#include "../App.h"
#include "../Vec.h"


#define WIDTH 128
#define HEIGHT 64

enum Tool{
    CURSER,
    PEN,
    ERASER
};

class Drawing: public App{

    private:
        Vec curser = Vec(WIDTH/2, HEIGHT/2);
        Tool tool = CURSER;
        bool toolIsActive = false;
        bool drawing[WIDTH][48];
    public:

        Drawing(Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App("Drawing", display, joystick, bluetooth){
            
        }

        void init(){
            App::init();
            delay(200);
        }

        bool inDrawBox(){
            return curser.getY()>16 && curser.getY()<HEIGHT && curser.getX()>0 && curser.getX()<WIDTH;
        }

        void update(){
            display->clearDisplay();
            if(tool == PEN && inDrawBox() && toolIsActive){
                drawing[curser.getX()][curser.getY()-17] = 1;
            }
            else if(tool == ERASER && inDrawBox() && toolIsActive){
                drawing[curser.getX()][curser.getY()-17] = 0;
                drawing[curser.getX()][curser.getY()-16] = 0;
                drawing[curser.getX()][curser.getY()-18] = 0;
                drawing[curser.getX()-1][curser.getY()-17] = 0;
                drawing[curser.getX()+1][curser.getY()-17] = 0;
            }
            drawBackButton();
            drawCurserButton();
            drawEraserButton();
            drawPenButton();
            drawSendButton();
            drawImage();
            drawCurser();
            if(toolIsActive){
                display->setCursor(112, 0);
                display->setTextSize(1);
                display->print("A");
            }
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

        void drawBackButton(){
            display->setCursor(0, 0);
            display->setTextSize(1);
            display->print("<-");
        }

        void drawPenButton(){
            display->setCursor(16, 0);
            display->setTextSize(1);
            display->print("P");
        }

        void drawEraserButton(){
            display->setCursor(32, 0);
            display->setTextSize(1);
            display->print("E");
        }

        void drawCurserButton(){
            display->setCursor(48, 0);
            display->setTextSize(1);
            display->print("C");
        }

        void drawSendButton(){
            display->setCursor(64, 0);
            display->setTextSize(1);
            display->print("S");
        }

        bool overBackButton(){
            return curser.within(Vec(0, 16), Vec(0, 16));
        }

        bool overPenButton(){
            return curser.within(Vec(16, 32), Vec(0, 16));
        }

        bool overEraseButton(){
            return curser.within(Vec(32, 48), Vec(0, 16));
        }

        bool overCursorButton(){
            return curser.within(Vec(48, 64), Vec(0, 16));
        }

        bool overSendButton(){
            return curser.within(Vec(64, 70), Vec(0, 16));
        }

        void drawImage(){
            for(int i = 17; i < HEIGHT; i++){
                for(int j = 0; j < WIDTH; j++){
                    if(drawing[j][i-17] == 1){
                        display->drawPixel(j, i, WHITE);
                    }
                }
            }
        }


        void reset(){

        }


        void clickedButton(){
            delay(200);
            if(overBackButton()){
                close();
            }
            else if(overPenButton()){
                tool = PEN;
            }
            else if(overCursorButton()){
                tool = CURSER;
            }
            else if(overEraseButton()){
                tool = ERASER;
            }
            else if(overSendButton()){
                // ===================================================================================
                bluetooth->send("[");
                for(int i = 0; i < 48; i++){
                    for(int j = 0; j < WIDTH; j++){
                        String pixel = drawing[j][i] == 1 ? "1" : "0";
                        bluetooth->send(pixel);
                    }
                }
                bluetooth->send("]");
                //=====================================================
            }
            else{
                toolIsActive = !toolIsActive;
            }
        };

        void movedUp(){
            if(curser.within(Vec(0, 128), Vec(1, 64))){
                curser.setY(curser.getY()-1);
            }
        };

        void movedDown(){
            if(curser.within(Vec(0, 128), Vec(0, 63))){
                curser.setY(curser.getY()+1);
            }
        };

        void movedRight(){
            if(curser.within(Vec(0, 127), Vec(0, 64))){
                curser.setX(curser.getX()+1);
            }
        };

        void movedLeft(){
            if(curser.within(Vec(1, 128), Vec(0, 64))){
                curser.setX(curser.getX()-1);
            }
        };

        void close(){
            App::close();
        }

};