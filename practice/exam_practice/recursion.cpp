#include<iostream>
using namespace std;

/* int factorial(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}

int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return n+sum(n-1);
    }
}

int fib(int num)
{
    if(num==0||num==1)
    {
        return num;
    }
    else
    {
        return fib(num-1)+fib(num-2);
    }
}  */


int factorial(int n,int fact=1)
{
    if(n==1)
    {
        return fact;
    }
    else
    {
        return factorial(n-1,fact*n);
    }
}

int sum(int n,int sums=0)
{
    if(n==0)
    {
        return sums;
    }
    
    else
    {
        return sum(n-1,sums+n);
    }
}

int fib(int n,int a=0,int b=1)
{
    if(n==0)
    {
        return a;
    }
    if(n==1)
    { 
        return b;
    }
    

        return fib(n-1,b,a+b);
    
}

int main()
{
    int num;
    cout<<"Enter the no to find the factorail: ";
    cin>>num;
    
    cout<<"The factorial is: "<<factorial(num)<<endl;

    cout<<"The sum is: "<<sum(num)<<endl;

    cout<<"The fibonacci no is: "<<fib(num)<<endl;

    return 0;
}