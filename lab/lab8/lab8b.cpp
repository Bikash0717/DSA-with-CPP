#include<iostream>
using namespace std;
#define max 5

class Sort
{
    private:
    int *s;
    int size;
    public:
    Sort(int arr[],int size)
    {
        s=new int[size];
        this->size=size;
         for(int i=0;i<size;i++)
    {
        s[i]=arr[i];
    }
    }

    void insertion_sort()
    {
        int temp,j;
        for(int k=1;k<size;k++)
        {
            temp=s[k];
            j=k-1;
            while(j>=0 && temp<=s[j])
            {
                s[j+1]=s[j];
                j--;
            }
            s[j+1]=temp;
        }
    }


    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }
    ~Sort()
    {
        delete[] s;
    }
};

int main()
{
int arr[]={4, 2, 3, 1, 5};
Sort obj(arr,5);
cout<<" Before sorting: ";
obj.display();
obj.insertion_sort();
cout<<" After sorting: ";
obj.display();
}