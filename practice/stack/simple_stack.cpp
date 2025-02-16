#include<iostream>
using namespace std;

class Stack
{
    int size,*s,top=-1;
    public:
    Stack(int v)
    {
        s=new int(v);
        size=v;
    }
    int isEmpty()
    {
        if(top==-1)
        {
            return 1;
        }
        else 
        {

            return 0;
        }
    }
    int isFull()
    {
        if(top==size-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push(int value)
    {
        if(isFull())
        {
            cout<<"Stack is full!"<<endl;
        }
        top++;
        s[top]=value;
        cout<<value<<" is pushed in the stack"<<endl;
        
    }
    
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty!"<<endl;
        }
        
        cout<<s[top]<<" value is popped!"<<endl;
        top--;
    }

    void display()
    {
       for(int i=0;i<=top;i++)
        {
            cout<<s[i]<<" ";
        }
     cout<<endl;
    }

    void peek(int index)
    {
        cout<<s[top-index+1]<<endl;
    }
};


int main()
{
Stack s1(5);
s1.push(4);
s1.push(5);
s1.push(6);
s1.push(7);
s1.peek(2);
s1.display();
s1.pop();
s1.display();
s1.peek(2);

}