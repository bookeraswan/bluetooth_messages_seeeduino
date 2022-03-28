
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Bluetooth.h"
#include "JoyStick.h"
#include "App.h"
#include "apps/MainMenu.h"
#include "apps/TicTacToe.h"
#include "apps/Clock.h"
#include "apps/Coordinates.h"
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



Bluetooth bt;
JoyStick js(1,0, 2);

Clock clock("Clock", &display, &js, &bt);
TicTacToe t2("Tic Tac Toe", &display, &js, &bt);
Coordinates t3(&display, &js, &bt);
TicTacToe t4("Fibonacci", &display, &js, &bt);
TicTacToe t5("Sleep Game", &display, &js, &bt);
TicTacToe t6("Pac Man", &display, &js, &bt);
TicTacToe t7("Hang Man", &display, &js, &bt);
TicTacToe t8("Snake", &display, &js, &bt);
TicTacToe t9("Pong", &display, &js, &bt);
TicTacToe t10("Pacman", &display, &js, &bt);

App *apps[10] = {&clock, &t2, &t3, &t4, &t5, &t6, &t7, &t8, &t9, &t10};

int num_apps = 10;

MainMenu menu(apps, num_apps, &display, &js, &bt);


void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.display();
  SerialUSB.begin(9600);
  menu.init();
}


void loop(){
    //display.drawPixel(127, 0, WHITE);
    menu.update();
}
