#include<iostream>
using namespace std;
int main()
{
char ch[30];
cin.getline(ch,30);
int flag=0;
int c=0;
for(int i=0;ch[i]!=NULL;i++)
{
if(ch[i]==32)
{
flag=0;
}
else
{
if(flag==0)
c++;
flag=1;
}
}
int k=-1;
int p=0;
flag=0;
for(int i=0;ch[i]!=NULL;i++)
{
    if(ch[i]==32||ch[i+1]=='\0')
    {
        if(flag==1)
        {
            p++;
            if(p==c)
                ch[++k]='\0';
            else
                ch[++k]=' ';
            flag=0;
        }
    }
    else
    {
        ch[++k]=ch[i];
        flag=1;
    }
}
cout<<ch;
}
