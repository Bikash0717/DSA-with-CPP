#include<iostream>
using namespace std;

class Diagonal
{
    private:
    int n;
    int *A;
    public:
    Diagonal(int n)
    {
        this->n=n;
        A=new int[n];
    }

    void set(int i,int j,int x);
    int get(int i,int j);
    void Display();
    ~Diagonal();

};

void Diagonal::set(int i,int j, int x)
{
    if(i==j)
    {
        A[i-1]=x;
    }
}

int Diagonal::get(int i,int j)
{
    if(i==j)
    {
        return A[i-1];
    }
    else
    {
        return 0;
    }
}

void Diagonal::Display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                cout<<A[i];
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

Diagonal::~Diagonal()
{
    delete[] A;
}

int main()
{
    Diagonal m(3);
    m.set(1,1,3);
    m.set(2,2,5);
    m.set(3,3,8);
    m.Display();
    m.get(2,1);
    return 0;
}