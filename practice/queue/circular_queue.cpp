#include<iostream>
using namespace std;


class Queue
{
    private:
    int front,rear,size,*Q;
    public:
    Queue(int size)
    {
        this->size=size;
        Q=new int[this->size];
        front=rear=-1;
    }

    void enqueue(int value)
    {
        if((front==0&&rear==size-1)||rear==front-1)
        {
            cout<<"Queue is full!"<<endl;
            return;
        }
        else if(front==-1)
        {
            front=rear=0;
        }
        else if(rear==size-1&&front!=0)
        {
            rear=0;
        }
        else{
        rear++;
        }
        Q[rear]=value;
        cout<<value<<" is enqueue!"<<endl;
        
    }

    void dequeue()
    {
        int x;

        if(front==rear)
        {
            cout<<"Queue is empty!"<<endl;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else{
            x=Q[front];
            cout<<x<<" is dequeue!"<<endl;
            front++;
        }
         
         
    }

    void display()
    {
        if(front<=rear)
        {
        for(int i=front;i<=rear;i++)
        {
            cout<<Q[i]<<" ";
        }
        }
        else{
            for(int i=front;i<size;i++)
        {
            cout<<Q[i]<<" ";
        }
        for(int i=0;i<=rear;i++)
        {
            cout<<Q[i]<<" ";
        }
        }
        
        cout<<endl;
    }
    

};


int main()
{
Queue q1(3);
q1.enqueue(3);
q1.enqueue(5);
q1.enqueue(7);
q1.enqueue(9);
q1.display();
q1.dequeue();
q1.dequeue();
q1.enqueue(9);
q1.display();
}