#include "../App.h"

class TicTacToe: public App{
    String board = "_________";
    String str;
    bool clicked = false;
    int pointer = 0;
    char turn = 'x';
    bool back = false;
    bool open = false;
    public:

        TicTacToe(String name, Adafruit_SSD1306 *display,JoyStick *joystick, Bluetooth *bluetooth):App(name, display, joystick, bluetooth){

        }
        
        void update(){
            display->clearDisplay();
            display->setTextSize(1);
            display->setCursor(120, 0);
            display->print(pointer);

            if(joystick->pressed()){
                if(back){
                    close();
                }
                else if(board[pointer] == '_'){
                    board[pointer] = turn;
                    if(turn == 'x'){
                        turn = 'o';
                    }
                    else{
                        turn = 'x';
                    }
                }

            }
            String j_direction = joystick->getDirection();
            if(j_direction == "Right"){
            pointer++;
            }else if(j_direction == "Left"){
            pointer--;
            }
            else if(j_direction == "Up"){
                back = true;
            }
            else if(j_direction == "Down"){
                back = false;
            }
            if(back){
                display->setCursor(0, 0);
                display->setTextSize(1);
                display->print("<-");
            }
            printBoard(board);
            display->display();
        }


        void printBoard(String board){
            display->setTextSize(2);
            display->setCursor(0, 16);
            display->print("  ");
            display->print(board[0]);
            display->print(" ");
            display->print(board[1]);
            display->print(" ");
            display->print(board[2]);
            display->print("   ");

            display->print("  ");
            display->print(board[3]);
            display->print(" ");
            display->print(board[4]);
            display->print(" ");
            display->print(board[5]);
            display->print("   ");

            display->print("  ");
            display->print(board[6]);
            display->print(" ");
            display->print(board[7]);
            display->print(" ");
            display->print(board[8]);
            display->print("   ");
        }
};