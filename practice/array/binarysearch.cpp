#include<iostream>
using namespace std;

struct array{
    int A[10];
    int length;
    int size;
};

int binarysearch(struct array arr,int val)   //iterative version
{
    int l,h,mid;
    l=0;
    h=arr.length-1;

    while(l<=h)
    {
        mid=(l+h)/2;
        if(val==arr.A[mid])
        {
            return mid;
        }
        else if(val>arr.A[mid])
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return -1;
}


int binarysearch2(int A[],int l,int h,int val)   //recursive version
{
    int mid;


    while(l<=h)
    {
        mid=(l+h)/2;
        if(val==A[mid])
        {
            return mid;
        }
        else if(val<A[mid])
        {
           return binarysearch2(A,l,mid-1,val);
        }
        else
        {
            return binarysearch2(A,mid+1,h,val);
        }
    }
    return -1;
}



void display(struct array arr)
{
for (int i=0;i<arr.length;i++)
{
cout<<arr.A[i]<<" ";
}
cout<<endl;
}

int main()
{
    struct array arr={{1,2,3,4,5},5,10};
    display(arr);
   

   cout<<"The value is found at index: "<<binarysearch(arr,4)<<endl;
    cout<<"The value is found at index: "<<binarysearch(arr,3)<<endl;
    
}