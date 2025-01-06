#include<iostream>
using namespace std;

int fib(int n)
{
   
    if(n<=1)
    {
        return n;
    }
    
    else
    {    
     return fib(n-2)+fib(n-1);   
    }
}



int main()
{
    int n,r;
    cout<<"Enter the n";
    cin>>n;

    r=fib(n);
    cout<<r<<endl;
    
    return 0;
}
