#include<iostream>
using namespace std;

//int A[10]={2,4,6,8,10},length=5,size=10;
int length2=8,size2=10,A2[10]={-1,4,-6,5,7,2,-9,-3};
/* void insert(int n)
{
    if(length<=size)
    {
        int i=length-1;
        while(A[i]>n)
        {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=n;
        length++;
    }
    
} */

void Rearrange()
{
    int i,j;
    i=0;
    j=length2-1;

    while(i<j)
    {
        if(A2[i]<0)
        {
            i++;
        }
        if(A2[j]>0)
        {
            j--;
        }
        if(i<j)
        {
            swap(A2[i],A2[j]);
        }
    }
}

void display()
{
    for(int i=0;i<length2;i++)
    {
        cout<<A2[i]<<" ";
    }
    cout<<endl;
}

int main()
{


//insert(7);

display();
Rearrange();
display();

}