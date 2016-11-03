#include "rgb_lcd.h"
rgb_lcd lcd;

void setup()
{
 lcd.begin(16, 2);
}

void loop()
{
  //code snippets
  lcd.clear();
  lcd.setRGB(255, 255, 255);
        lcd.setCursor(0,0);
        lcd.print("TEXT ");
        //lcd.print(variable);
}

