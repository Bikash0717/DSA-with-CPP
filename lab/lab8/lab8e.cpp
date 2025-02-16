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
        merge_sort(0,size-1); 
    }

    void merge_sort(int beg,int end)
    {
       if(beg<end)
       {
        int mid=(beg+end)/2;
        merge_sort(beg,mid);
        merge_sort(mid+1,end);
        merge(beg,mid,end);
       }
    }

void merge(int beg,int mid, int end)
    {
        int temp[size];
        int i=beg,j=mid+1,index=0; 
        while(i<=mid && j<=end)
        {
            if(s[i]<s[j])
            {
                temp[index]=s[i];
                i++;
            }
            else
            {
                temp[index]=s[j];
                j++;
            }
            index++;
        }
        if(i>mid)
        {
            while(j<=end)
            {
                temp[index]=s[j];
                index++;
                j++;
            }
        }
        else
        {
            while(i<=mid)
            {
                temp[index]=s[i];
                index++;
                i++;
            }
        }
        int k=0;
        while(k<index)
        {
            s[k+beg]=temp[k];
            k++;
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
int arr[]={8, 6, 7, 1, 5};
Sort obj(arr,5);
cout<<" Before sorting: ";
obj.display();

obj.sorting();
cout<<" After sorting: ";
obj.display();
}