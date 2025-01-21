#include<iostream>
using namespace std;

int pow1(int m,int n)
{
    if(n==0)
    {
        return 1;
        
    }
    else
    {
        return pow1(m,n-1)*m;
    }
}

int pow2(int m,int n)
{
    if(n==0)
    {
        return 1;
        
    }
    if(n%2==0)
    {
        return pow2(m*m,n/2);
    }
    else
    {
        return m*pow2(m*m,(n-1)/2);
    }
}

int main()
{
    int r,n,m;
    cout<<"Enter the value and power m,n";
    cin>>m>>n;
     r=pow1(m,n);
    cout<<"The result is :"<<r<<endl<<endl;
     r=pow2(m,n);
    cout<<"The result is :  "<<r<<endl;
    return 0;
}
