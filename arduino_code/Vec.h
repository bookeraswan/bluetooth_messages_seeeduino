#pragma once

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