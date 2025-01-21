#include<iostream>
using namespace std;

struct array{
    int A[10];
    int length;
    int size;
};


struct array* unionsorted(struct array *arr1,struct array *arr2)
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
    else if(arr1->A[i]>arr2->A[j])
    {
        arr3->A[k]=arr2->A[j];
        k++;
        j++;
    }
    else
    {
        arr3->A[k]=arr2->A[j];
        k++;
        i++;
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
    arr3->length=k;
   return arr3;

}


struct array* intersection_sorted(struct array *arr1,struct array *arr2)
{
   struct array *arr3=new array;
   int i=0,j=0,k=0;
   while(i<arr1->length&&j<arr2->length)
   {
    if(arr1->A[i]<arr2->A[j])
    {
        i++;
    }
    else if(arr1->A[i]>arr2->A[j])
    {
        j++;
    }
    else
    {
        arr3->A[k]=arr2->A[j];
        k++;
        i++;
        j++;
    }

   }
  
    arr3->length=k;
   return arr3;

}

struct array* difference_sorted(struct array *arr1,struct array *arr2)
{
   struct array *arr3=new array;
   int i=0,j=0,k=0;
   while(i<arr1->length&&j<arr2->length)
   {
    if(arr1->A[i]<arr2->A[j])
    {
        arr3->A[k]=arr1->A[i];
        i++;
        k++;
    }
    else if(arr1->A[i]>arr2->A[j])
    {
        j++;
    }
    else
    {
        i++;
        j++;
    }

   }
    for(;i<arr1->length;i++)
   {
    arr3->A[k]=arr1->A[i];
    k++;
   }
    arr3->length=k;
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
    struct array arr2={{0,1,2,5,8},5,10};
    display(arr1);
    display(arr2);
    struct array *arr3;
    cout<<"Union : ";
    arr3=unionsorted(&arr1,&arr2);
    display(*arr3);

    cout<<"Intersection : ";
    arr3=intersection_sorted(&arr1,&arr2);
    display(*arr3);

    cout<<"Difference : ";
    arr3=difference_sorted(&arr1,&arr2);
    display(*arr3);
    
}