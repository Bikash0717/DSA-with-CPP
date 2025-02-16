#include<iostream>
using namespace std;


class Sort
{
    private:
    int *s;
    int size,beg,end,loc;
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

    void sorting()
    {
        quick_sort(0,size-1);
    }

    void quick_sort(int beg,int end)
    {
       if(beg<end)
       {
        int loc=partition(beg,end);
        quick_sort(beg,loc-1);
        quick_sort(loc+1,end);
       }
    }

int partition(int beg, int end)
    {
        int left = beg, right = end;
        int pivot = s[beg];  
        while (left < right)
        {
             if(s[left] <= pivot && left <= end)
            {
                left++;
            }
            if(s[right] > pivot && right >= beg)
            {
                right--;
            }
                if (left < right)
            {
                swap(s[left], s[right]);
            }
        }
        swap(s[beg], s[right]);  
        return right;  
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

obj.sorting();
cout<<" After sorting: ";
obj.display();
}