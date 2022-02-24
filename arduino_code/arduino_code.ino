
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Bluetooth.h"
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



Bluetooth bt;
String str;

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
    String message = bt.getText();
    if(message.length() > 0){
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0, 28);
      display.print(message);
      display.display();
    }
    delay(100);
}
