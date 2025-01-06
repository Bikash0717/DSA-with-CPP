#include<iostream>
using namespace std;

int sum(int n)
{
    if(n>0)
    {
        return sum(n-1)+n;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int r,n;
    cout<<"Enter the n";
    cin>>n;
     r=sum(n);
    cout<<"The sum of "<<n<<" number is :"<<r<<endl;
    return 0;
}
