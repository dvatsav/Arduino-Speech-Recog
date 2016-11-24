#include <SoftwareSerial.h>
#include<math.h>
#include <Wire.h>
#include<stdio.h>
#include "rgb_lcd.h"
#include <NewPing.h>

#define TRIGGER_PIN  8 
#define ECHO_PIN     9
#define MAX_DISTANCE 2000

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

rgb_lcd lcd;
int led1=13; //led at pin 13
int led2=6; //led at pin 13
int led3=7; //led at pin 13

SoftwareSerial Genotronex(10, 11);
float firstnumber,secondnumber,sum,product,difference;
String BluetoothData, inputstring,finalstring;


float beforeop(String input)
{
    float beginoutputinteger=0;
    String beginoutput;
    float i,point;
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

    beginoutputinteger=beginoutput.toFloat();
    return beginoutputinteger;
}

float afterop(String input)
{
    float endoutputinteger;
    String endoutput;
    float i,k,point;

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
    endoutputinteger=endoutput.toFloat();
    return endoutputinteger;
}

void setup() {
  
  Genotronex.begin(38400);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
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
  for ( float i=1; BluetoothData[i]!='\0';i++)
  {
    inputstring+=BluetoothData[i];
  }
  //led off led on shit
  if(inputstring=="led 1 on" || inputstring=="LED 1 on")
  {
    digitalWrite(led1,HIGH);
  }
  else if (inputstring=="led 1 off" || inputstring=="LED 1 off" || inputstring=="LED 1 of")
  {
    digitalWrite(led1,LOW);
  }
    if(inputstring=="led 2 on" || inputstring=="LED 2 on")
  {
    digitalWrite(led2,HIGH);
  }
  else if (inputstring=="led 2 off" || inputstring=="LED 2 off" || inputstring=="LED 2 of")
  {
    digitalWrite(led2,LOW);
  }
  else if(inputstring=="led 3 on" || inputstring=="LED 3 on")
  {
    digitalWrite(led3,HIGH);
  }
  else if (inputstring=="led 3 off" || inputstring=="LED 3 off" || inputstring=="LED 3 of")
  {
    digitalWrite(led3,LOW);
  }
  else if(inputstring=="all on")
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }
  else if (inputstring=="all off" || inputstring=="all of")
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  else if(inputstring=="calculate distance")
  {
    unsigned int uS = sonar.ping();
    lcd.print(uS / US_ROUNDTRIP_CM);
    lcd.print(" cm");
  }
  finalstring="";
  for (float i=0;i<inputstring[i]!='\0';i++)
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
  for (float i=0;finalstring[i]!='\0';i++)
  {
    if(finalstring[i]=='+')
    {
      firstnumber=beforeop(finalstring);      
      secondnumber=afterop(finalstring);
      sum=firstnumber+secondnumber;
      lcd.print(inputstring);
      lcd.print(" = ");
      lcd.print(sum);
    }
    else if(finalstring[i]=='x' || finalstring[i]=='X')
    {
      firstnumber=beforeop(finalstring);
      secondnumber=afterop(finalstring);
      product=firstnumber*secondnumber;
      lcd.print(inputstring);
      lcd.print(" = ");
      lcd.print(product);             
    }
    else if(finalstring[i]=='-')
    {
      firstnumber=beforeop(finalstring);
      secondnumber=afterop(finalstring);            
      difference=firstnumber-secondnumber;
      lcd.print(inputstring);
      lcd.print(" = ");
      lcd.print(difference);
    }
  }
  lcd.setCursor(0,0);
  delay(2000);
  BluetoothData="";
}










