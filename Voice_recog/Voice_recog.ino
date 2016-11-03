#include <SoftwareSerial.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

SoftwareSerial Genotronex(10, 11);
int led1 = 13,flag;
String BluetoothData, newdata;

void setup() {
  
  Genotronex.begin(38400);
  pinMode(led1, OUTPUT);
  lcd.begin(16, 2);
}

void loop() 
{
  flag=0;
  lcd.clear();
  lcd.setRGB(255, 255, 255);
  while (Genotronex.available())
  {
    char c = Genotronex.read();
    if (c == '#'){break;}
    BluetoothData+=c;
  }  
<<<<<<< HEAD

  /*
    if (BluetoothData == "*TV on") 
=======
    if (BluetoothData == "*turn me on") 
>>>>>>> 3f4f41b0b1d430cf9fe155ca5c9b6faf356d35f2
    {
      digitalWrite(led1, 1);
    }
    if (BluetoothData == "*turn me off") 
    { 
      digitalWrite(led1, 0);      
    }*/
delay(100);
newdata="";
for ( int i=1; BluetoothData[i]!='\0';i++)
{
   newdata+=BluetoothData[i];
   if(BluetoothData[i]=="+")
   {
    flag=1;
   }
   else if(BluetoothData[i]=="-")
   {
    flag=2;
   }
   else if(BluetoothData[i]=="x")
   {
    flag=3;
   }   
}
if(flag==1)
{
  for (int i=0; newdata[i]!='\0';i++)
  {
    if(newdata[i]="+")
    {
      for(int j=0;j<=i-2;j++)
      {
        number1+=newdata[j];
      }
    }
  }
}



lcd.setCursor(0,0);
lcd.print(newdata);
delay(5000);
BluetoothData="";
}




