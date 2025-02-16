#include<iostream>
using namespace std;

class Node 
{
    public:
int data;
Node *next;
};


class Stack
{
    private:
    Node *top;
    public:
    Stack()
    {
        top=NULL;
        }
        void push(int x);
        void pop();
        void display();
        void peek(int pos);
};

void Stack::push(int x)
{
    Node *t=new Node;
    if(t==NULL)
    {
        cout<<"Stack is full!"<<endl;
    }
    else
    {
        t->data=x;
        t->next=top;
        top=t;
        cout<<top->data<<" is pushed!"<<endl;
    }
}

void Stack::pop()
{
    if(top==NULL)
    {
        cout<<" Stack is empty!"<<endl;
    }
    else
    {

        Node *t=top;
        cout<<top->data<<" is popped"<<endl;
        top=top->next;
        delete t;
    }
}

void Stack::display()
{
    Node *t=top;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}

void Stack::peek(int pos)
{
    Node *t=top;
    for(int i=0;i<pos-1;i++)
    {
       t=t->next;
    }
    cout<<t->data<<endl;
}

int main()
{
Stack s1;
s1.push(1);
s1.push(2);
s1.push(3);
s1.push(4);
s1.push(5);
s1.peek(2);
s1.display();
s1.pop();
s1.pop();
s1.display();


}