#include<iostream>
using namespace std;

int fun(int n)
{ 
   int x=0;
    if(n>0)
    {
        x++;
        return fun(n-1)+x;    
    }
    return 0;
}

int main()
{
    int r;
    r=fun(5);
    cout<<r;
    return 0;
}