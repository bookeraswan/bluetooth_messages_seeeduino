  
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
#include "apps/Ball.h"
#include "apps/Chrome.h"
#include "apps/Camera.h"
#include "apps/VsCode.h"
#include "apps/WhatsApp.h"
#include "apps/Netflix.h"
#include "apps/Pong.h"
#include "apps/Drawing.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Bluetooth bt;
JoyStick js(1, 0, 2);

#define NUMAPPS 11

Clock clock("Clock", &display, &js, &bt);
TicTacToe t2("Tic Tac Toe", &display, &js, &bt);
Coordinates t3(&display, &js, &bt);
Chrome t4("Chrome", &display, &js, &bt);
Camera t5("Camera", &display, &js, &bt);
VsCode t6("Vs Code", &display, &js, &bt);
WhatsApp t7("WhatsApp", &display, &js, &bt);
Netflix t8("Netflix", &display, &js, &bt);
Ball ball(&display, &js, &bt);
Pong pong(&display, &js, &bt);
Drawing drawing(&display, &js, &bt);

App *apps[NUMAPPS] = {&clock, &t2, &t3, &t4, &t5, &t6, &t7, &ball, &t8, &pong, &drawing};

int num_apps = NUMAPPS;

MainMenu menu(apps, num_apps, &display, &js, &bt);

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  menu.init();
}

void loop()
{
  
  menu.update();

  if(js.pressed()) menu.clickedButton();

  switch (js.getDirection()){
    case RIGHT:
      menu.movedRight();
      break;

    case LEFT:
      menu.movedLeft();
      break;

    case UP:
      menu.movedUp();
      break;

    case DOWN:
      menu.movedDown();
      break;
  }

}
