#include<iostream>
using namespace std;

int l=8;
int size=10;
int A[10]={5,6,7,7,7,14,14,15};  //sorted array
int A2[10]={5,8,7,7,7,15,14,15}; //unsorted array
int H[8]={0};

void finding_dublicate1()
{
   int lastdublicate=0;
   for(int i=0;i<l;i++)
   {
    if(A[i]==A[i+1] && lastdublicate!=A[i])
    {
        lastdublicate=A[i];
        cout<<A[i]<<" is dublicate!"<<endl;
    }
   }

}


void finding_no_of_dublicate()
{

   for(int i=0;i<l-1;i++)
   {
    if(A[i]==A[i+1])
    {
        int j=i+1;
        while(A[j]==A[i])
        {
            j++;
        }
        cout<<A[i]<<" is appearing "<<j-i<<" times"<<endl;
    }
   }

}

void finding_dublicate2()   //finding dublicate by using hash method
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
        if(H[i]>1)
        {
            cout<<i<<" is repeating "<<H[i]<<" times"<<endl;
        }
    }
}


void finding_dublicate3()
{
  
   for(int i=0;i<l;i++)
   {
     int count=1;
     if(A2[i]!=-1)
     {
    for(int j=i+1;j<l;j++)
    {
        
        if(A2[i]==A2[j])
        {
            A2[j]=-1;
            count++;
        }
    }
    if(count>1)
    {
    cout<<A2[i]<<" is repeated "<<count<<" times"<<endl;
    }
    }
   }
   
}

int main()
{
   
    // finding_dublicate1();
   // finding_no_of_dublicate();
  //finding_dublicate2();
   finding_dublicate3();
   
}