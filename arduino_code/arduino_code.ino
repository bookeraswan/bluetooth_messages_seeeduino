
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include "Bluetooth.h"
//#include "JoyStick.h"
#include "App.h"
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



Bluetooth bt;
JoyStick js(1,0, 2);
String str;
bool clicked = false;
int pointer = 0;
char turn = 'x';

String board = "_________";


void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
      display.clearDisplay();
      display.setTextSize(3);
      display.setCursor(0, 28);
      display.print('E');
      display.display();
  SerialUSB.begin(9600);
}


void loop(){
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print(pointer);
    display.setTextSize(2);
    display.setCursor(0, 16);
    if(js.pressed()){
      if(board[pointer] == '_'){
        board[pointer] = turn;
        if(turn == 'x'){
          turn = 'o';
        }
        else{
          turn = 'x';
        }
      }
    }
    String j_direction = js.getDirection();
    if(j_direction == "Right"){
      pointer++;
    }else if(j_direction == "Left"){
      pointer--;
    }
    
    printBoard(board);
    display.display();
    delay(200);
}


void printBoard(String board){
  display.print("  ");
    display.print(board[0]);
    display.print(" ");
    display.print(board[1]);
    display.print(" ");
    display.print(board[2]);
    display.print("   ");

    display.print("  ");
    display.print(board[3]);
    display.print(" ");
    display.print(board[4]);
    display.print(" ");
    display.print(board[5]);
    display.print("   ");

    display.print("  ");
    display.print(board[6]);
    display.print(" ");
    display.print(board[7]);
    display.print(" ");
    display.print(board[8]);
    display.print("   ");
}
