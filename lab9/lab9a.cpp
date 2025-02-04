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

    void linear_Search(int value)
    {
        int pos=-1;
       for(int i=0;i<size;i++)
       {
        if(s[i]==value)
        {
            pos=i+1;
            cout<<"The value is found at position: "<<pos<<endl;
        }
       }
       if(pos==-1)
       {
        cout<<"Value is not present is the array!"<<endl;
       }
    }
    ~Search()
    {
        delete[] s;
    }
};

int main()
{
int arr[]={4, 2, 3, 1, 5};
Search obj(arr,5);
obj.linear_Search(1);
}