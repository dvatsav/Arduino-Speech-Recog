#include <SoftwareSerial.h>

SoftwareSerial Genotronex(10, 11);
int led1 = 13;
String BluetoothData;

void setup() {
  
  Genotronex.begin(38400);
  pinMode(led1, OUTPUT);
}

void loop() 
{
  
  while (Genotronex.available())
  {
    char c = Genotronex.read();
    if (c == '#'){break;}
    BluetoothData+=c;
  }  
    if (BluetoothData == "*TV on") 
    {
      digitalWrite(led1, 1);
    }
    if (BluetoothData == "*TV off") 
    { 
      digitalWrite(led1, 0);      
    }
delay(100);
BluetoothData="";
}
  

