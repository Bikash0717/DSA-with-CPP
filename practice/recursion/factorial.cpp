#include<iostream>
using namespace std;

int fact(int n)
{
    if(n==0)
    {
        return 1;
        
    }
    else
    {
        return fact(n-1)*n;
    }
}

int main()
{
    int r,n;
    cout<<"Enter the n";
    cin>>n;
     r=fact(n);
    cout<<"The factorial of "<<n<<" number is :"<<r<<endl;
    return 0;
}
