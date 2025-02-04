#include<iostream>
using namespace std;

class Symmetric
{
    private:
    int n;
    int *A;
    public:
    Symmetric(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    void create();
    void set(int i,int j,int x);
    int get(int i,int j);
    void Display();
    ~Symmetric();

};

/* void Symmetric::set(int i,int j, int x)
{
    if(i>=j)
    {
        A[(i*(i-1)/2)+j-1]=x;
    }
}

int Symmetric::get(int i,int j)
{
    if(i>=j)
    {
        return A[(i*(i-1)/2)+j-1];
    }
    else
    {
        return 0;
    }
}

void Symmetric::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
            {
                cout<<A[(i*(i-1)/2)+j-1];
            }
            else
            {
                cout<<"0";
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

Symmetric::~Symmetric()
{
    delete[] A;
} */

void Symmetric::create()
{
    int x;
      for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;
           if(i>=j)
           {
           
            A[n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
           }
        }
    }
}

void Symmetric::set(int i,int j, int x)  //column major
{
    if(i>=j)
    {
        A[n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
    }
}

int Symmetric::get(int i,int j)
{
    if(i>=j)
    {
        return A[n*(j-1)+(j-2)*(j-1)/2+i-j];
    }
    else
    {
        return A[(i*(i-1)/2)+j-1];
    }
}

void Symmetric::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
            {
                cout<<A[n*(j-1)+(j-2)*(j-1)/2+i-j];
            }
            else 
            {
               cout<<A[(i*(i-1)/2)+j-1];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

Symmetric::~Symmetric()
{
    delete[] A;
}


int main()
{
    int n,x;
    cout<<"Enter the dimension of the matrix:";
    cin>>n;
    Symmetric m(n);
    m.create();
    m.Display();
    cout<<m.get(2,3);
    return 0;
}