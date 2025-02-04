#include<iostream>
using namespace std;
#define max 5

class Search
{
    private:
    int *s;
    int size;
    public:
    Search(int arr[],int size)
    {
        s=new int[size];
        this->size=size;
         for(int i=0;i<size;i++)
    {
        s[i]=arr[i];
    }
    }

    void binary_search_iterative(int value)
    {
        int l,h,mid,pos=-1;
    l=0;
    h=size-1;
    
    while(l<=h)
    {
        mid=(l+h)/2;
        if(value==s[mid])
        {
            pos=mid+1;
            cout<<"The value is found at the position: "<<pos<<endl;
            return;
        }
        else if(value>s[mid])
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
        
    }
    if(pos==-1)
        {
            cout<<" The found is not found!"<<endl;
        }
    
    }

    void binary_search_recursion(int value)
    {
        int l=0;
        int h=size-1;
        int pos=binary_search_recursive(value,l,h);
        cout<<"The value is found at position: "<<pos+1<<endl;
    }

    int binary_search_recursive(int value,int l, int h)
    {
        int mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(value==s[mid])
            {
                return mid;
            }
            else if(value<s[mid])
            {
                return binary_search_recursive(value,l,mid-1);
            }
            else
            {
                return  binary_search_recursive(value,mid+1,h);
            }
        }
        return -1;
    }

    ~Search()
    {
        delete[] s;
    }
};

int main()
{
int arr[]={1,2,5,7,8};
Search obj(arr,5);
obj.binary_search_iterative(7);
obj.binary_search_recursion(5);
}