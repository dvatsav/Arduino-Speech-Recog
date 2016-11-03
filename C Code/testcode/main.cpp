#include <iostream>
#include<string.h>

using namespace std;

int main()
{
    int flag=0,k=0;
    char newdata[80],number1[80];
    char BluetoothData[]={"*6 + 3"};
    int length=strlen(BluetoothData);
    cout<<BluetoothData[3]<<endl;
for ( int i=1; i<length;i++)
{
    strcpy(newdata[k],BluetoothData[i]);
   /*if((int)BluetoothData[i]==43)
   {
    flag=1;
   }*/
   k++;
   cout<<BluetoothData<<newdata[k]<<"This is the end"<<endl;
   /*else if(BluetoothData[i]=="-")
   {
    flag=2;
   }
   else if(BluetoothData[i]=="x")
   {
    flag=3;
   }*/
}
cout<<newdata<<endl;
if(flag==1)
{
  for (int i=0; newdata[i]!='\0';i++)
  {
    if((int)newdata[i]==43)
    {
      for(int j=0;j<=i-2;j++)
      {
        number1[j]=newdata[j];
      }
    }
  }
}

cout<<number1<<endl;
cout<<newdata;
return 0;
}
