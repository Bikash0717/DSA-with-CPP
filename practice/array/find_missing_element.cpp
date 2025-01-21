#include<iostream>
using namespace std;

int l=8;
int size=10;
int A[10]={5,6,7,8,10,13,14,15};
int H[8]={0};
void findingsingle()
{
    int lo,h,diff,n;
    lo=A[0];
    h=A[l-1];
    n=h-lo;
    diff=lo-0;
    for(int i=0;i<n;i++)
    {
         
        if((A[i]-i)!=diff)
        {
            cout<<"The missing is :"<<i+diff;
            break;
        }
    }

}


void findingmultiple()
{
    int lo,h,diff,n;
    lo=A[0];
    h=A[l-1];
    n=h-lo;
    diff=lo-0;
    for(int i=0;i<n;i++)
    {
        
        if((A[i]-i)!=diff)
        {
            while((diff<A[i]-i))
            {
            cout<<"The missing is :"<<i+diff<<endl;
            diff++;
            }
        }
    }

}

void findingmultiple2()
{
    int lo,h,n;
    lo=A[0];
    h=A[l-1];
    n=h-lo;
    for(int i=0;i<n;i++)
    {
        H[A[i]]++;
    }
    for(int i=lo;i<=h;i++)
    {
        if(H[i]==0)
        {
            cout<<i<<" is missing:"<<endl;
        }
    }
}

int main()
{
   // findingsingle();
    findingmultiple2();
   
}