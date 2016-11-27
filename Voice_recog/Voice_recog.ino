#include <SoftwareSerial.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

SoftwareSerial Genotronex(10, 11);
int led1 = 13;
String BluetoothData, newdata;

void setup() {
  
  Genotronex.begin(38400);
  pinMode(led1, OUTPUT);
  lcd.begin(16, 2);
}

void loop() 
{
  lcd.clear();
  lcd.setRGB(255, 255, 255);
  while (Genotronex.available())
  {
    char c = Genotronex.read();
    if (c == '#'){break;}
    BluetoothData+=c;
  } 
   
    if (BluetoothData == "*led on") 
    {
      digitalWrite(led1, 1);
    }
    if (BluetoothData == "*led off") 
    { 
      digitalWrite(led1, 0);      
    }
delay(100);
newdata="";
for ( int i=1; BluetoothData[i]!='\0';i++)
{
   newdata+=BluetoothData[i];
}

lcd.setCursor(0,0);
lcd.print(newdata);
delay(5000);
BluetoothData="";
}

// Code Referred From: http://www.instructables.com






