#include<iostream>
using namespace std;
void fun(int a[50][50],int row,int col,int pos,int pos1)
{
if( a[pos][pos1] == -1 || pos<0 || pos>row-1 || pos1<0 || pos1>col-1)
    return;
else
    {
    if(a[pos][pos1] != 0)
    {
        a[pos][pos1]=0;
    fun(a,row,col,pos,pos1+1);
    fun(a,row,col,pos+1,pos1);
    fun(a,row,col,pos,pos1-1);
    fun(a,row,col,pos-1,pos1);
    }
}
}
int main()
{
int row,col;
cin>>row>>col;
int a[50][50];
for(int i=0;i<row;i++)
for(int j=0;j<col;j++)
cin>>a[i][j];
int pos,pos1;
cin>>pos>>pos1;
fun(a,row,col,pos,pos1);
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
cout<<a[i][j]<<" ";
cout<<endl;
}
}
