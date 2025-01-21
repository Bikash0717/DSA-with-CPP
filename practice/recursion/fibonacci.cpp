#include<iostream>
using namespace std;
int A[10];
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



int fib2(int n)
{
    if(n<=1)
    { 
        A[n]=n;
        return n;
    }
    else
    {
        if(A[n-2]==-1)
        {
            A[n-2]=fib(n-2);
        }
        if(A[n-1]==-1)
        {
            A[n-1]=fib(n-1);
        }
        return A[n-2]+A[n-1];
    }
}



int main()
{
    int n,r;
    cout<<"Enter the n";
    cin>>n;
   
    r=fib(n);
    cout<<r<<endl;
    
    for(int i = 0; i < 10; i++) {
        A[i] = -1;
    }

    r=fib2(n);
    cout<<r<<endl;
    
    return 0;
}
