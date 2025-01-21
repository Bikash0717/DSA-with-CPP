#include<iostream>
using namespace std;

struct array{
    int A[10];
    int length;
    int size;
};


void append(struct array *arr,int val)
{
    if(arr->length<arr->size)
    {
    arr->A[arr->length++]=val;
   // arr->length++;
    }

}



void insert(struct array *arr,int index,int val)
{
    if(index>=0 && index<=arr->length)
    {
    for(int i=arr->length;i>index;i--)
    {
        arr->A[i]=arr->A[i-1];
    }
    arr->A[index]=val;
    arr->length++;
    }
}


void del(struct array *arr,int index)
{
    for(int i=index;i<arr->length-1;i++)
    {
        arr->A[i]=arr->A[i+1];
    }
    arr->length--;

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
    append(&arr,6);
    display(arr);
    insert(&arr,3,8);
    display(arr);
    del(&arr,4);
    display(arr);
}