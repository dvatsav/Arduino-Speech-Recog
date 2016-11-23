#include <SoftwareSerial.h>
#include<math.h>
#include <Wire.h>
#include<stdio.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

SoftwareSerial Genotronex(10, 11);
int led1 = 13, firstnumber,secondnumber;
String BluetoothData, inputstring,finalstring;


int beforeop(char* input)
{
    int var=0;
    char beginoutput[50];
    int i=0,k=0,point;
    for (i=0;input[i]!='\0';i++)
    {
        if(input[i]=='+' || input[i]=='-' || input[i]=='x')
        {
            point=i;
            break;
        }
    }
    for(i=0,k=0;i<point;i++,k++)
    {
        beginoutput[k]=input[i];
    }

    int endpos[500];
    for(int y=0;y<k;y++)
    {
        endpos[y]=int(beginoutput[y])-48;
    }

    for(int y=k-1,x=0;y>=0;y--,x++)
    {
        var=var+(pow(10,x)*endpos[y]);
    }

    return var;
}

int afterop(char* input)
{
    int var=0;
    char endoutput[50];
    int i,k,point;

    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]=='+'|| input[i]=='x' || input[i]=='-')
        {
            point=i;
            break;
        }
    }
    for(i=point+1,k=0;input[i]!='\0';i++,k++)
    {
        endoutput[k]=input[i];

    }
    int endpos[500];
    for(int y=0;y<k;y++)
    {
        endpos[y]=int(endoutput[y])-48;

    }

    for(int y=k-1,x=0;y>=0;y--,x++)
    {
        var=var+(pow(10,x)*endpos[y]);
    }
    return var;
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
   
   delay(100);
  inputstring="";
for ( int i=1; BluetoothData[i]!='\0';i++)
{
   inputstring+=BluetoothData[i];
}
lcd.print(inputstring);

    finalstring="";
    for (int i=0;i<inputstring[i]!='\0';i++)
    {
        if (inputstring[i]!=' ')
        {
            finalstring+=inputstring[i];
        }
    }
    Serial.println(finalstring);
    firstnumber=0;
    secondnumber=0;
    //to find the mathematical operator
    for (int i=0;finalstring[i]!='\0';i++)
    {
        if(finalstring[i]=='+')
        {
            Serial.println("addition operator found");
            /*firstnumber=afterop(finalstring);
            secondnumber=beforeop(finalstring);
            int sum=firstnumber+secondnumber;
            Serial.print("Sum is: ");
            Serial.println(sum,DEC);*/
        }
        else if(finalstring[i]=='x')
        {
            Serial.println("multiplication operator found");
            /*firstnumber=afterop(finalstring);
            secondnumber=beforeop(finalstring);
            int product=firstnumber*secondnumber;
            Serial.print("Product is: ");
            Serial.println(product,DEC);   */             
        }
        else if(finalstring[i]=='-')
        {
            Serial.println("subraction operator found");
            /*firstnumber=afterop(finalstring);
            secondnumber=beforeop(finalstring);            
            int difference=firstnumber-secondnumber;
            Serial.print("Difference is: ");
            Serial.println(difference,DEC);*/
        }
    }

lcd.setCursor(0,0);
delay(5000);
BluetoothData="";
}










