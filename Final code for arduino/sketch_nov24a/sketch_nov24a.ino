#include <SoftwareSerial.h>
#include<math.h>
#include <Wire.h>
#include<stdio.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

SoftwareSerial Genotronex(10, 11);
int led1 = 13, firstnumber,secondnumber,sum,product,difference;
String BluetoothData, inputstring,finalstring;


int beforeop(String input)
{
    int beginoutputinteger=0;
    String beginoutput;
    int i,point;
    for (i=0;input[i]!='\0';i++)
    {
        if(input[i]=='+' || input[i]=='-' || input[i]=='x')
        {
            point=i;
            break;
        }
    }
    for(i=0;i<point;i++)
    {
        beginoutput+=input[i];
    }

    beginoutputinteger=beginoutput.toInt();
    return beginoutputinteger;
}

int afterop(String input)
{
    int endoutputinteger;
    String endoutput;
    int i,k,point;

    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]=='+'|| input[i]=='x' || input[i]=='-')
        {
            point=i;
            break;
        }
    }
    for(i=point+1;input[i]!='\0';i++)
    {
        endoutput+=input[i];
    }
    endoutputinteger=endoutput.toInt();
    return endoutputinteger;
}

void setup() {
  
  Genotronex.begin(38400);
  pinMode(led1, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
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
  inputstring="";
  for ( int i=1; BluetoothData[i]!='\0';i++)
  {
    inputstring+=BluetoothData[i];
  }
  finalstring="";
  for (int i=0;i<inputstring[i]!='\0';i++)
  {
    if (inputstring[i]!=' ')
    {
      finalstring+=inputstring[i];
    }
  }
  firstnumber=0;
  secondnumber=0;
  sum=0;
  product=0;
  difference=0;
  for (int i=0;finalstring[i]!='\0';i++)
  {
    if(finalstring[i]=='+')
    {
      firstnumber=beforeop(finalstring);      
      secondnumber=afterop(finalstring);
      sum=firstnumber+secondnumber;
      lcd.print(sum);
    }
    else if(finalstring[i]=='x')
    {
      firstnumber=beforeop(finalstring);
      secondnumber=afterop(finalstring);
      product=firstnumber*secondnumber;
      lcd.print(product);             
    }
    else if(finalstring[i]=='-')
    {
      firstnumber=beforeop(finalstring);
      secondnumber=afterop(finalstring);            
      difference=firstnumber-secondnumber;
      lcd.print(difference);
    }
  }
  lcd.setCursor(0,0);
  delay(5000);
  BluetoothData="";
}










