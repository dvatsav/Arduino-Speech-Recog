#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;


string beforeop(string input)
{ string output;

   int i=0,k=0;
   for (i=0;input[i]!='\0';i++)
   {
    //cout<<input[i]<<endl;
        if(input[i]=='+' || input[i]=='-' || input[i]=='x'){
        //cout<<"i value : "<<i<<"j value : "<<k<<"input[i] : "<<input[i]<<"output[k] : "<<output[k]<<"BREAKING"<<endl;
            break;
            }
        output[k]=input[i];
        k+=1;
        //cout<<"i value : "<<i<<"j value : "<<k<<"input[i] : "<<input[i]<<"output[k] : "<<output[k]<<endl;
   }
   /*while(input[i]!='+' || input[i]!='-' || input[i]!='x')
   	{
   		output[k++]=input[i];
   		i+=1;
   		if(i==input.lenlength())
            break;
   	}*/   //cout<<"END"<<endl;
   //for (i=0;i<k;i++)
    //    cout<<output[i];
    //cout<<endl;
   return output;
}
void afterop(char* input)
{ char output[50];
  int i,k,point;
  char a;
  //cout<<"input "<<strlen(input)<<endl;
  cin>>a; 
  for(i=0;input[i]!='\0';i++)
    { if(input[i]=='+'|| input[i]=='x' || input[i]=='-')
          {point=i;
           break;
          }
    }
    cout<<"point="<<point<<endl;
    for(i=point+1,k=0;input[i]!='\0';i++,k++)
      { //cout<<"i="<<i<<endl;
    //cout<<"k="<<k<<endl;
cin>>a;
        
        output[k]=input[i];
        //cout<<output[k];
        cin>>a;

      //cout<<output[k];
      }
      int lengthoutput=strlen(input)-1-point;
      //cout<<lengthoutput<<endl;

      //cout<<"input "<<strlen(input)<<endl;
      //cout<<"output"<<strlen(output)<<endl;
      for(i=0;i<lengthoutput;i++)
        //cout<<output[i];
      //cout<<endl;
    //cout<<output;
    //clrscr();
   // cout<<outputt
}
int main()
{   char potato[500]="6+7988",testvar[100];
   afterop(potato);
  //clrscr();

	//for (int i=0;testvar[i]!='\0';i++)
	{
	//	cout<<testvar[i];
	}
	return 0;
}
