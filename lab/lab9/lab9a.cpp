#include<iostream>
using namespace std;


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
int key;
Search obj(arr,5);

cout<<"Enter the value to search:";
cin>>key;
obj.linear_Search(key);
}