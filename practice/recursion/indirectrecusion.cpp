#include<iostream>
using namespace std;
void funcB(int);
void funcA(int n)
{
if(n>0)
{
    cout<<n<<"\t";
    funcB(n-1);
}
}
void funcB(int n)
{
if(n>0)
{
    cout<<n<<"\t";
    funcA(n/2);
}
}

int main()
{
    funcA(20);
    return 0;

}