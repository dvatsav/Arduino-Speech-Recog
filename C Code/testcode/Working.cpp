#include<iostream>

using namespace std;

int main()
{
int i;
char test1[]={"*6 + 3"};
char test2[80];
int b,c;
for(i=0;test1[i]!='\0';i++);

int k=0;

for(int j=1;j<i;j++)
{
    test2[k++]=test1[j];
}

int a;
for(int j=0;j<i;j++)
{
    if(int(test2[j])==43)
        a=j;
}
b=int(test2[a-2])-'0';
c=int(test2[a+2])-'0';
cout<<b+c;
return 0;

}
