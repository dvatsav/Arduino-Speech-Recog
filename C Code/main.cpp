#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>
#include<cmath>

using namespace std;
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

int main()
{
    char inputstring[500]="*12 + 30";
    char finalstring[500];
    int k=0;

    int firstnumber=0,secondnumber=0;
    for (int i=1;i<inputstring[i]!='\0';i++)
    {
        if (inputstring[i]!=' ')
        {
            finalstring[k]=inputstring[i];
            k++;
        }
    }
    //to find the mathematical operator
    for (int i=0;finalstring[i]!='\0';i++)
    {
        if(finalstring[i]=='+')
        {
            firstnumber=afterop(finalstring);
            secondnumber=beforeop(finalstring);
            cout<<"Sum is: "<<firstnumber+secondnumber<<endl;
        }
        else if(finalstring[i]=='x')
        {
            firstnumber=afterop(finalstring);
            secondnumber=beforeop(finalstring);
            cout<<"Product is: "<<firstnumber*secondnumber<<endl;
        }
        else if(finalstring[i]=='-')
        {
            firstnumber=afterop(finalstring);
            secondnumber=beforeop(finalstring);
            cout<<"Difference is: "<<secondnumber-firstnumber<<endl;
        }
    }
	return 0;
}
