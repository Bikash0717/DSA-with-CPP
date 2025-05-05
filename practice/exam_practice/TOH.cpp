#include<iostream>
using namespace std;


void TOH(int n,char A,char B,char C)
{
    if(n==1)
    {
        cout<<A<<" to "<<C<<endl;
    }
    else
    {
        TOH(n-1,A,C,B);
        TOH(1,A,B,C);
        TOH(n-1,B,A,C);
    }
}

int main()
{
char A='A',B='B',C='C';
int n;
cout<<"Enter the no of disc";
cin>>n;
TOH(n,A,B,C);
}