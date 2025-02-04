#include<iostream>
using namespace std;

class Triangular
{
    private:
    int n;
    int *A;
    public:
    Triangular(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];
    }

    void set(int i,int j,int x);
    int get(int i,int j);
    void Display();
    ~Triangular();

};

/* void Triangular::set(int i,int j, int x)
{
    if(i>=j)
    {
        A[(i*(i-1)/2)+j-1]=x;
    }
}

int Triangular::get(int i,int j)
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

void Triangular::Display()
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

Triangular::~Triangular()
{
    delete[] A;
} */



void Triangular::set(int i,int j, int x)  //column major
{
    if(i>=j)
    {
        A[n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
    }
}

int Triangular::get(int i,int j)
{
    if(i>=j)
    {
        return A[n*(j-1)+(j-2)*(j-1)/2+i-j];
    }
    else
    {
        return 0;
    }
}

void Triangular::Display()
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
                cout<<"0";
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

Triangular::~Triangular()
{
    delete[] A;
}


int main()
{
    int n,x;
    cout<<"Enter the dimension of the matrix:";
    cin>>n;
    Triangular m(n);
   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            m.set(i,j,x);
        }
    }

    m.Display();
    cout<<m.get(2,1);
    return 0;
}