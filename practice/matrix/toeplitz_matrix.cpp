#include<iostream>
using namespace std;

class Toeplitz
{
    private:
    int n;
    int *A;
    public:
    Toeplitz(int n)
    {
        this->n=n;
        A=new int[2*n-1];
    }
    void create();
    void set(int i,int j,int x);
    int get(int i,int j);
    void Display();
    ~Toeplitz();

};


void Toeplitz::create()
{
    int x;
      for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            if(i<=j)
            {
                A[j-i]=x;
            }
           else
           {
            A[n+i-j-1]=x;
           }
        }
    }
}

void Toeplitz::set(int i,int j, int x)  //column major
{
    if(i<=j)
    {
        A[j-i]=x;
    }
    else
           {
            A[n+i-j-1]=x;
           }
}

int Toeplitz::get(int i,int j)
{
    if(i<=j)
    {
        return A[j-i];
    }
    else
    {
        return A[n+i-j-1];
    }
}

void Toeplitz::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<=j)
            {
                cout<<A[j-i];
            }
            else 
            {
               cout<<A[n+i-j-1];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

Toeplitz::~Toeplitz()
{
    delete[] A;
}


int main()
{
    int n,x;
    cout<<"Enter the dimension of the matrix:";
    cin>>n;
    Toeplitz m(n);
    m.create();
    m.Display();
    cout<<m.get(2,3);
    return 0;
}