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

    void selection_sort()
    {
   
        int pos;
        for(int k=0;k<size-1;k++)
        {
            pos=smallest(s,k,size);
            swap(s[k],s[pos]);
        }
    }

    int smallest(int s[],int k,int size)
    {
        int small=s[k];
        int pos=k;
        for(int j=k+1;j<size;j++)
        {
            if(small>s[j])
            {
                small=s[j];
                pos=j;
            }
           
        }
         return pos;
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
obj.selection_sort();
cout<<" After sorting: ";
obj.display();
}