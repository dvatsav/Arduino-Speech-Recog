#include <SoftwareSerial.h>
#include<math.h>
#include <Wire.h>
#include<stdio.h>
#include "rgb_lcd.h"
#include <NewPing.h>

#define maximum 2000
#define trigger  8 
#define echo     9
NewPing sonar(trigger, echo, maximum);

rgb_lcd lcd;
int tempPin = 0;
int buzzerPin=8;
int led1=13; //led at pin 13
int led2=6; //led at pin 13
int led3=7; //led at pin 13

SoftwareSerial Genotronex(10, 11);
int positionoftext,flagraisedto;
float firstnumber,secondnumber,sum,product,difference,division,exponent,temp;
String BluetoothData, inputstring,finalstring, addstring,firstnumberstring_raisedto,secondnumberstring_raisedto;




float beforeop(String input)
{
    float beginoutputinteger=0;
    String beginoutput;
    int i,point;
    for (i=0;input[i]!='\0';i++)
    {
        if(input[i]=='+' || input[i]=='-' || input[i]=='x' || input[i]=='X')
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
        if(input[i]=='+'|| input[i]=='x' || input[i]=='-' || input[i]=='X')
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



float aftermiddleterm(String input)
{
  int pointfirstspace,pointsecondspace;
  float endoutputinteger=0;
  String endoutput;
  for (int i=0;input[i]!='\0';i++)
  {
    if(input[i]==' ')
    {
      pointfirstspace=i;
      break;
    }
  }
  for (int i=pointfirstspace+1;input[i]!='\0';i++)
  {
    if(input[i]==' ')
    {
      pointsecondspace=i;
      break;
    }
  }
  for (int i=pointsecondspace+1;input[i]!='\0';i++)
  {
    endoutput+=input[i];
  }
  endoutputinteger=endoutput.toFloat();
  return endoutputinteger;
}

float beforemiddleterm(String input)
{
  int pointfirstspace,pointsecondspace;
  float beginoutputinteger=0;
  String beginoutput;
  for (int i=0;input[i]!='\0';i++)
  {
    if(input[i]==' ')
    {
      pointfirstspace=i;
      break;
    }
  }
  for (int i=pointfirstspace+1;input[i]!='\0';i++)
  {
    if(input[i]==' ')
    {
      pointsecondspace=i;
      break;
    }
  }
  for (int i=0;i<pointfirstspace;i++)
  {
    beginoutput+=input[i];
  }
  beginoutputinteger=beginoutput.toFloat();
  return beginoutputinteger;
}


void setup() {
  
  Genotronex.begin(38400);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}




void loop() 
{
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
  //led off led on shit
  if(inputstring=="led 1 on" || inputstring=="LED 1 on" || inputstring=="LED one on" || inputstring=="LED one on")
  {
    digitalWrite(led1,HIGH);
  }
  else if (inputstring=="led 1 off" || inputstring=="LED 1 off" || inputstring=="LED 1 of" || inputstring=="LED one off" || inputstring=="LED one of" || inputstring=="led one on")
  {
    digitalWrite(led1,LOW);
  }
    if(inputstring=="led 2 on" || inputstring=="LED 2 on" || inputstring=="LED two on" || inputstring=="led two on")
  {
    digitalWrite(led2,HIGH);
  }
  else if (inputstring=="led 2 off" || inputstring=="LED 2 off" || inputstring=="LED 2 of" || inputstring=="LED two on" || inputstring=="led two on")
  {
    digitalWrite(led2,LOW);
  }
  else if(inputstring=="led 3 on" || inputstring=="LED 3 on" || inputstring=="LED three on"|| inputstring=="led three of")
  {
    digitalWrite(led3,HIGH);
  }
  else if (inputstring=="led 3 off" || inputstring=="LED 3 off" || inputstring=="LED 3 of" || inputstring=="LED three of" || inputstring=="LED three off")
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
  else if(inputstring=="calculate distance" || inputstring=="tell me the distance")
  {
    unsigned int uS = sonar.ping();
    lcd.clear();
    lcd.print(uS / US_ROUNDTRIP_CM);
    lcd.print("cm");
    float dist=uS/US_ROUNDTRIP_CM;
    if(dist<20 && dist>=1)
    {
      digitalWrite(buzzerPin, HIGH);
      delay(2500);
      digitalWrite(buzzerPin, LOW);
    }
  }
  else if(inputstring=="tell me the temperature" || inputstring=="what's the temperature" || inputstring=="calculate temperature" || inputstring=="temperature")
  {
    temp = analogRead(tempPin);
    temp = (float)(1023 - temp)*10000/temp;
    temp = 1/(log(temp/10000)/3975+1/298.15)-273.15;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(temp,2);
    lcd.print((char)223);
    lcd.print("C");
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
  division=0;
  for (int i=0;finalstring[i]!='\0';i++)
  {
    if(finalstring[i]=='+')
    { 
      firstnumber=beforeop(finalstring);      
      secondnumber=afterop(finalstring);
      sum=firstnumber+secondnumber;
      lcd.clear();
      lcd.print(finalstring);
      lcd.print(" = ");
      lcd.print(sum);
    }
    else if(finalstring[i]=='x' || finalstring[i]=='X')
    {
      firstnumber=beforeop(finalstring);
      secondnumber=afterop(finalstring);
      product=firstnumber*secondnumber;
      lcd.clear();
      lcd.print(finalstring);
      lcd.print(" = ");
      lcd.print(product);             
    }
    else if(finalstring[i]=='-')
    {
      firstnumber=beforeop(finalstring);
      secondnumber=afterop(finalstring);   
      lcd.clear();         
      difference=firstnumber-secondnumber;
      lcd.print(finalstring);
      lcd.print(" = ");
      lcd.print(difference);
    }
  }
  addstring="";
  if(inputstring[0]=='a' && inputstring[1]=='d' && inputstring[2]=='d')
  {
    for (int i=4;inputstring[i]!='\0';i++)
    {
      addstring+=inputstring[i];
    }
    lcd.clear();
    firstnumber=beforemiddleterm(addstring);
    secondnumber=aftermiddleterm(addstring);
    sum=firstnumber+secondnumber;
    lcd.print(sum);
  }
  else if(inputstring[0]=='s' && inputstring[1]=='u' && inputstring[2]=='b' && inputstring[3]=='t' && inputstring[4]=='r' && inputstring[5]=='a' && inputstring[6]=='c' && inputstring[7]=='t')
  {
    for (int i=9;inputstring[i]!='\0';i++)
    {
      addstring+=inputstring[i];
    }
    firstnumber=beforemiddleterm(addstring);
    lcd.clear();
    secondnumber=aftermiddleterm(addstring);
    difference=secondnumber-firstnumber;
    lcd.print(difference);
  }
  else if(inputstring[0]=='m' && inputstring[1]=='u' && inputstring[2]=='l' && inputstring[3]=='t' && inputstring[4]=='i' && inputstring[5]=='p' && inputstring[6]=='l' && inputstring[7]=='y')
  {
    for (int i=9;inputstring[i]!='\0';i++)
    {
      addstring+=inputstring[i];
    }
    firstnumber=beforemiddleterm(addstring);
    secondnumber=aftermiddleterm(addstring);
    product=secondnumber*firstnumber;
    lcd.clear();
    lcd.print(product);
  }
  else if(inputstring[0]=='d' && inputstring[1]=='i' && inputstring[2]=='v' && inputstring[3]=='i' && inputstring[4]=='d' && inputstring[5]=='e')
  {
    for (int i=7;inputstring[i]!='\0';i++)
    {
      addstring+=inputstring[i];
    }
    firstnumber=beforemiddleterm(addstring);
    secondnumber=aftermiddleterm(addstring);
    division=firstnumber/secondnumber;
    lcd.clear();
    lcd.print(division);
  }
  flagraisedto=0;
  positionoftext=0;
  for (int i=0;inputstring[i]!='\0';i++)
  {
    if(inputstring[i]=='r' && inputstring[i+1]=='a' && inputstring[i+2]=='i' && inputstring[i+3]=='s' && inputstring[i+4]=='e' && inputstring[i+5]=='d' && inputstring[i+6]==' ' && inputstring[i+7]=='t' && inputstring[i+8]=='o')
    {
      positionoftext=i;
      flagraisedto=1;
    }
  }
  if(flagraisedto==1)
  {
    firstnumberstring_raisedto="";
    secondnumberstring_raisedto="";
    for (int i=0;i<positionoftext;i++)
    {
      firstnumberstring_raisedto+=inputstring[i];
    }
    for (int i=positionoftext+10;inputstring[i]!='\0';i++)
    {
      secondnumberstring_raisedto+=inputstring[i];
    }
    firstnumber=firstnumberstring_raisedto.toFloat();
    secondnumber=secondnumberstring_raisedto.toFloat();
    exponent=pow(firstnumber,secondnumber);
    lcd.clear();
    lcd.print(exponent);    
  }
  lcd.setCursor(0,0);
  delay(2000);
  BluetoothData="";
}










