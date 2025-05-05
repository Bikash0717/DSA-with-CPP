#include<iostream>
using namespace std;

struct node{
int data;
node *next;
};

node *front=NULL,*rear=NULL;

void enqueue(int value)
{
    node *newnode=new node;
    if(newnode==NULL)
    {
        cout<<"Queue is full!"<<endl;
    }
    newnode->data=value;
    newnode->next=NULL;
    cout<<value<<" is enqueued!"<<endl;
    if(front==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }

}

void dequeue()
{
int x=-1;
if(front==NULL)
{
    cout<<"Queue is empty!"<<endl;
}
else
{
    x=front->data;
    front=front->next;
    cout<<x<<" is dequeued!"<<endl;
}

}

void display()
{
    node *t=front;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}

int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
     display();
    dequeue();
    dequeue();
   
    display();
}

