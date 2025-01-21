#include<iostream>
using namespace std;

struct array{
    int A[10];
    int length;
    int size;
};


struct array* merge(struct array *arr1,struct array *arr2)
{
   struct array *arr3=new array;
   int i=0,j=0,k=0;
   while(i<arr1->length&&j<arr2->length)
   {
    if(arr1->A[i]<arr2->A[j])
    {
        arr3->A[k]=arr1->A[i];
        k++;
        i++;
    }
    else
    {
        arr3->A[k]=arr2->A[j];
        k++;
        j++;
    }

   }
   for(;i<arr1->length;i++)
   {
    arr3->A[k]=arr1->A[i];
    k++;
   }

    for(;j<arr2->length;j++)
   {
    arr3->A[k]=arr1->A[j];
    k++;
   }
    arr3->length=arr1->length+arr2->length;
   return arr3;

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
    struct array arr1={{1,3,5,7,9},5,10};
    struct array arr2={{0,2,4,6,8},5,10};
    display(arr1);
    display(arr2);
    struct array *arr3;
    arr3=merge(&arr1,&arr2);
    display(*arr3);
    
}