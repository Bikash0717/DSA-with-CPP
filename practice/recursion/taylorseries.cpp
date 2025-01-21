#include<iostream>
using namespace std;

double e(int x,int n)
{
    static double p=1,f=1;
    double r;
    if(n==0)
    {
        return 1;
        
    }
    else
    {
        r=e(x,n-1);
        p*=x;
        f*=n;
        return r+p/f;
    }
}



int main()
{
    int x,n;
    double r;
    cout<<"Enter the value pf x and n";
    cin>>x>>n;
    r=e(x,n);
    cout<<"The result is :  "<<r<<endl;
    return 0;
}
