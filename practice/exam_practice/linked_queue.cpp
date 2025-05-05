#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *front=NULL;
Node *rear=NULL;




    void enqueue(int value)
    {
        Node *newnode=new Node;
        newnode->data=value;
        if(front==NULL)
        {
            front=rear=newnode;
            newnode->next=rear->next=NULL;
          
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
            rear->next=NULL;
            
        }
        cout<<value<<" is enqueued in queue!"<<endl;
    }
    void dequeue()
    {
        if (front==NULL)
        {
            cout<<"UNDERFLOW!"<<endl;
            return;
        }
        Node *ptr=front;
        cout<<front->data<<" is dequeued from queue!"<<endl;
        front=front->next;
        delete ptr;

    
        }

    void display()
    {
        Node *ptr=front;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }

int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
    dequeue();
    display();

}