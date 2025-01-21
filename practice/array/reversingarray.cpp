#include<iostream>
using namespace std;

int l=5;

void reversing(int A[])
{
    for(int i=0,j=l-1;i<j;i++,j--)
    {
        swap(A[i],A[j]);
    }
}

void reversing2(int A[])
{ 
    int B[5];
    for(int i=0,j=l-1;i<l;i++,j--)
    {
        B[i]=A[j];
    }
    for(int i=0;i<l;i++)
    {
        A[i]=B[i];
    }
}

void display(int A[])
{
    for(int i=0;i<l;i++)
    {
        cout<<A[i]<<" ";
    }
}

int main()
{
    int A[5]={1,2,3,4,5};
    reversing2(A);
    display(A);
}