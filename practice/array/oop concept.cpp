#include<iostream>
using namespace std;

class arr
{
    private:
        int *A;
        int length;
        int size;
    public:
        arr()
        {
            size=10;
            length=0;
            A=new int [size];
        }

          arr(int n)
        {
            size=n;
            length=0;
            A=new int [size];
        }
        ~arr()
        {
            delete []A;
        }
        void append(int val);
        void insert(int index,int val);
        void del(int index);
        void reversing();
        int linearsearch(int val);
        int binarysearch(int val);
        void display();
};

void arr::append(int val)
{
    if(length<size)
    {
    A[length++]=val;
   // length++;
    }

}



void arr::insert(int index,int val)
{
    if(index>=0 && index<=length)
    {
    for(int i=length;i>index;i--)
    {
        A[i]=A[i-1];
    }
    A[index]=val;
    length++;
    }
}


void arr::del(int index)
{
    for(int i=index;i<length-1;i++)
    {
        A[i]=A[i+1];
    }
    length--;

}

void arr::reversing()
{ 
    int B[5];
    for(int i=0,j=length-1;i<length;i++,j--)
    {
        B[i]=A[j];
    }
    for(int i=0;i<length;i++)
    {
        A[i]=B[i];
    }
}


int arr::linearsearch(int val)
{
    for(int i=0;i<length;i++)
    {
        if(A[i]==val)
        {
            return i;
        }
    }
    return 0;
}


int arr::binarysearch(int val)   //iterative version
{
    int l,h,mid;
    l=0;
    h=length-1;

    while(l<=h)
    {
        mid=(l+h)/2;
        if(val==A[mid])
        {
            return mid;
        }
        else if(val>A[mid])
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return -1;
}

void arr::display()
{
for (int i=0;i<length;i++)
{
cout<<A[i]<<" ";
}
cout<<endl;
}



int main()
{
 arr a1(10);

 a1.insert(0,0);
 a1.insert(1,1);
 a1.append(2);
 a1.append(3);
 a1.display();
 a1.reversing();
 a1.display();
 a1.insert(0,4);
 a1.display();
 a1.reversing();
 a1.display();
 cout<<"binary:"<<a1.binarysearch(2)<<endl;
 cout<<"linear:"<<a1.linearsearch(1)<<endl;
 a1.del(1);
 a1.display();
}