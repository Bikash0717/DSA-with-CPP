#include<iostream>
using namespace std;

double e(int x,int n)
{
    static double s=1;
   
    if(n==0)
    {
        return s;
        
    }
    else
    {
        s=1+x*s/n;
        return e(x,n-1);
    }
}



int main()
{
    int x,n;
    double r;
    cout<<"Enter the value pf x and n";
    cin>>x>>n;

    cout<<"The result is :  "<<e(x,n)<<endl;
    return 0;
}
