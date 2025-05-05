#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *top;




    void push(int value)
    {
        Node *newnode=new Node;
        newnode->data=value;
        if(top==NULL)
        {
            newnode->next=NULL;
            top=newnode;
        }
        else
        {
            newnode->next=top;
            top=newnode;
        }
        cout<<value<<" is pushed in stack!"<<endl;
    }
    void pop()
    {
        if (top==NULL)
        {
            cout<<"UNDERFLOW!"<<endl;
            return;
        }
        Node *ptr=top;
        cout<<top->data<<" is Popped from stack!"<<endl;
        top=top->next;
        delete ptr;

    
        }

    void display()
    {
        Node *ptr=top;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }

int main()
{
    push(5);
    push(6);
    push(7);
    display();
    pop();
    pop();
    display();

}