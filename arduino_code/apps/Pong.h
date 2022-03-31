#include "../App.h"
#include "../Vec.h"
#include <cmath>

#define PADDLE_LEN 20

class Pong: public App{

    private:

    Vec position = Vec(10, 10);
    Vec velocity = Vec(3, -1);

    int collisionRadius = 4;

    int line[PADDLE_LEN][2];

    bool gameOver = false;

    int choice = 1;

    String options[2] = {"Back", "Play Again"};

    public:

        Pong(Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App("Pong", display, joystick, bluetooth){
            setTopOfLine(1);
        }

        int getPosX(){return position.getX();}
        int getPosY(){return position.getY();}

        void setPosX(int x){position.setX(x);}
        void setPosY(int y){position.setY(y);}

        int getVelocityX(){return velocity.getX();}
        int getVelocityY(){return velocity.getY();}

        void setVelocityX(int x){velocity.setX(x);}
        void setVelocityY(int y){velocity.setY(y);}

        int getScreenHeight(){return 64;}
        int getScreenWidth(){return 128;}

        int getTopOfLine(){
            return line[0][1];
        }

        void setTopOfLine(int y){
            if(y <= getScreenHeight() - PADDLE_LEN && y >= 1){
                for(int i = 0; i < PADDLE_LEN; i++){
                    line[i][0] = 1;
                    line[i][1] = y+i;
                }
            }
        }

        void drawLine(){
            for(int i = 0; i < PADDLE_LEN; i++){
                display->drawPixel(1, line[i][1], WHITE);
            }
        }

        void update(){
            display->clearDisplay();
            if(gameOver){
                delay(150);
                display->clearDisplay();
                display->setTextSize(2);
                display->setCursor(10, 10);
                display->print("You Lost!");
                display->setTextSize(1);
                display->setCursor(30, 50);
                display->print(options[choice]);
            }
            else{
                drawCircle(getPosX(), getPosY(), collisionRadius);
                drawLine();
                move();
            }

            display->display();

            if(joystick->pressed()) {
                if(choice == 0) close();
                reset();
                delay(200);
            }
            if(joystick->getDirection() == "Up"){
                if(gameOver){
                    choice = 0;
                }else{
                    setTopOfLine(getTopOfLine()-1);
                }
            }
            else if(joystick->getDirection() == "Down"){
                if(gameOver){
                    choice = 1;
                }else{
                    setTopOfLine(getTopOfLine()+1);
                }
            }
        }


        void reset(){
            position = Vec(10, 10);
            velocity = Vec(3, -1);
            gameOver = false;
            choice = 1;
            setTopOfLine(1);
        }

        // void drawCircle(int x, int y, int radius){
        //     for(int i = 0; i < getScreenHeight(); i++){
        //         for(int j = 0; j < getScreenWidth(); j++){
        //             int lhs = std::pow(x-j, 2) + std::pow(y-i, 2);
        //             int rhs = std::pow(radius, 2);
        //             if(lhs <= rhs){
        //                 display->drawPixel(j, i, WHITE);
        //             }
        //         }
        //     }
        // }

        void drawCircle(int center_x, int center_y, int radius){
            for(int x = center_x; x <= center_x+radius; x++){
                int y = center_y;
                bool in_circle = true;
                do
                {
                    display->drawPixel(x, y, WHITE);
                    display->drawPixel(x, 2*center_y-y, WHITE);
                    display->drawPixel(2*center_x-x, y, WHITE);
                    display->drawPixel(2*center_x-x, 2*center_y-y, WHITE);
                    in_circle = std::pow(x-center_x, 2) + std::pow(y-center_y, 2) <= std::pow(radius, 2);
                    y++;
                } while (in_circle);                
            }
        }

        void move(){

            if(getPosY() <= collisionRadius){
                setVelocityY(getVelocityY()*-1);
                setVelocityX(getVelocityX()*(1));
                setPosY(collisionRadius);
            }

            if(getPosY() >= getScreenHeight()-collisionRadius){
                setVelocityY(getVelocityY()*-1);
                setVelocityX(getVelocityX()*(1));
                setPosY(getScreenHeight()-collisionRadius);
            }

            if(getPosX() >= getScreenWidth()-collisionRadius){
                setVelocityY(getVelocityY()*1);
                setVelocityX(getVelocityX()*(-1));
                setPosX(getScreenWidth()-collisionRadius);
            }

            if(getPosX() <= collisionRadius && getPosX() >= -collisionRadius && getPosY() > getTopOfLine() && getPosY() < getTopOfLine()+PADDLE_LEN){
                setVelocityY(getVelocityY()*1);
                setVelocityX(getVelocityX()*(-1));
                setPosX(collisionRadius);
            }
            else if(getPosX() <= collisionRadius){
                gameOver = true;
            }
            position.add(velocity);
        }
};



// 
//             else 

