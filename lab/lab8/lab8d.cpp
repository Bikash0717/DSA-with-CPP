#include<iostream>
using namespace std;


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

    void shell_sort()
    {
        int flag=1,gap_size=size;
        while(flag==1||gap_size>1)
        {
            flag=0;
            gap_size=(gap_size+1)/2;
            for(int i=0;i<size-gap_size;i++)
            {
                if(s[i+gap_size]<s[i])
                {
                    swap(s[i+gap_size],s[i]);
                    flag=1;
                }
            }
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
int arr[]={7, 2, 8, 1, 5};
Sort obj(arr,5);
cout<<" Before sorting: ";
obj.display();
obj.shell_sort();
cout<<" After sorting: ";
obj.display();
}