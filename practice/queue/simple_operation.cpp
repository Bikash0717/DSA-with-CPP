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
        if(rear==size-1)
        {
            cout<<"Queue is full!"<<endl;
        }

        
        else{
        rear++;
        Q[rear]=value;
        cout<<value<<" is enqueue!"<<endl;
        }
    }

    void dequeue()
    {
        int x;
        if(front==rear)
        {
            cout<<"Queue is empty!"<<endl;
        }
        else
        {
            front++;
            x=Q[front];
            cout<<x<<" is denqueue!"<<endl;
      
        }
         
    }

    void display()
    {
        for(int i=front+1;i<=rear;i++)
        {
            cout<<Q[i]<<" ";
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