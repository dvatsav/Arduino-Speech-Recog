#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>

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
        var=var+(10^(x)*endpos[y]);
        cout<<var<<" ";
    }
    cout<<"\n"<<var;
    //stringstream convert(endoutput);
    //convert>>var;
    return var;
}

int main()
{
    char inputstring[500]="6+200";
    int firstnumber=0,secondnumber=0;
    //to find the mathematical operator
    for (int i=0;inputstring[i]!='\0';i++)
    {
        if(inputstring[i]=='+')
        {
            firstnumber=afterop(inputstring);
            secondnumber=beforeop(inputstring);
            cout<<"Sum is: "<<firstnumber+secondnumber<<endl;
        }
        else if(inputstring[i]=='x')
        {
            firstnumber=afterop(inputstring);
            secondnumber=beforeop(inputstring);
            cout<<"Product is: "<<firstnumber*secondnumber<<endl;
        }
        else if(inputstring[i]=='-')
        {
            firstnumber=afterop(inputstring);
            cout<<firstnumber<<endl;// if this line is commented, the answer changes to a wrong value. HOW
            secondnumber=beforeop(inputstring);
            cout<<"Difference is: "<<secondnumber-firstnumber<<endl;
        }
    }
	return 0;
}
