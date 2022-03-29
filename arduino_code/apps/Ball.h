#include "../App.h"
#include <cmath>

class Vec{

    private:

        int x;
        int y;

    public:
        Vec(int x, int y){
            setX(x);
            setY(y);
        }

        int getX(){ return x;}
        int getY(){ return y;}
        
        void setX(int x){ this->x = x;}
        void setY(int y){ this->y = y;}

        void add(Vec otherVector){
            setX(getX() + otherVector.getX());
            setY(getY() + otherVector.getY());
        }
};

class Ball: public App{

    private:

    Vec position = Vec(10, 10);
    Vec velocity = Vec(3, -4);
    Vec gravity  = Vec(0, 1);

    int collisionRadius = 10;

    public:

        Ball(Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App("Ball", display, joystick, bluetooth){}

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

        void update(){
            display->clearDisplay();
            drawCircle(getPosX(), getPosY(), collisionRadius);
            display->display();
            move();
            if(joystick->pressed()) close();
        }

        void drawCircle(int x, int y, int radius){
            for(int i = 0; i < getScreenHeight(); i++){
                for(int j = 0; j < getScreenWidth(); j++){
                    int lhs = std::pow(x-j, 2) + std::pow(y-i, 2);
                    int rhs = std::pow(radius, 2);
                    if(lhs <= rhs){
                        display->drawPixel(j, i, WHITE);
                    }
                }
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

            if(getPosX() <= collisionRadius){
                setVelocityY(getVelocityY()*1);
                setVelocityX(getVelocityX()*(-1));
                setPosX(collisionRadius);
            }
            else if(getPosX() >= getScreenWidth()-collisionRadius){
                setVelocityY(getVelocityY()*1);
                setVelocityX(getVelocityX()*(-1));
                setPosX(getScreenWidth()-collisionRadius);
            }

            velocity.add(gravity);
            position.add(velocity);
        }
};


