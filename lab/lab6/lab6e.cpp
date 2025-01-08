#include<iostream>
using namespace std;

/* int TOH(int n,int A,int B ,int C)
{
   
   if(n>0)
    {    
     TOH(n-1,A,C,B);
     cout<<A<<" to "<<C<<endl;
     TOH(n-1,B,A,C);
    }
} */


void TOH2(int n,char A,char B ,char C)
{

    if(n==1)
    {
        cout<<A<<" to "<<C<<endl;
    }
   
    else
    {    
     TOH2(n-1,A,C,B);
     TOH2(1,A,B,C);
     TOH2(n-1,B,A,C);
    }
}


int main()
{
    //int n,A=1,B=2,C=3;
    int n;
    char A='A',B='B',C='C';
    cout<<"Enter n:";
    cin>>n;

    TOH2(n,A,B,C);
    
    return 0;
}
