#include<iostream>
using namespace std;

int C(int n,int r)
{
   
    if(r==0||n==r)
    {
        return 1;
    }
    
    else
    {    
     return C(n-1,r-1)+C(n-1,r);   
    }
}





int main()
{
    int n,r;
    cout<<"Enter the n and r";
    cin>>n>>r;
   
    
    cout<<C(n,r)<<endl;
    
    
    
    return 0;
}
