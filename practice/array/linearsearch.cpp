#include<iostream>
using namespace std;

struct array{
    int A[10];
    int length;
    int size;
};

int linearsearch(struct array arr,int val)
{
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]==val)
        {
            return i;
        }
    }
}

int linearsearch2(struct array *arr,int val) ///improving linear search through transposition
{
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==val)
        {
            swap(arr->A[i-1],arr->A[i]);
            return i;
        }
    }
}

int linearsearch3(struct array *arr,int val)  //improving linear search by moving to front/head
{
    for(int i=0;i<arr->length;i++)
    {
        if(val==arr->A[i])
        {
            swap(arr->A[0],arr->A[i]);
            return i;
        }
    }
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
   

   cout<<"The value is found at index: "<<linearsearch(arr,3)<<endl;
   cout<<"The value is found at index: "<<linearsearch2(&arr,4)<<endl;
   display(arr);
    cout<<"The value is found at index: "<<linearsearch3(&arr,3)<<endl;
   display(arr);
    
}