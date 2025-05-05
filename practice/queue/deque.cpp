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

    void renqueue(int value)
    {
        if(rear==size-1)
        {
            cout<<"Queue is full!"<<endl;
        }

        
        else{
        rear++;
        Q[rear]=value;
        cout<<value<<" is renqueue!"<<endl;
        }
    }

       void fenqueue(int value)
    {
        if(front==-1)
        {
            cout<<"Queue is full!"<<endl;
        }

        
        else{
        
        Q[front]=value;
        front--;
        cout<<value<<" is fenqueue!"<<endl;
        }
    }

    void fdequeue()
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
            cout<<x<<" is fdequeue!"<<endl;
       
        }
         
    }

     void rdequeue()
    {
        int x;
        if(front==rear)
        {
            cout<<"Queue is empty!"<<endl;
        }
        else
        {
            x=Q[rear];
            cout<<x<<" is rdqueue!"<<endl;
        rear--;
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

q1.renqueue(7);
q1.renqueue(9);
q1.renqueue(6);
q1.renqueue(10);
q1.display();

q1.fdequeue();
q1.fdequeue();
q1.display();
q1.fenqueue(3);
q1.fenqueue(5);
q1.fenqueue(10);
q1.display();

q1.rdequeue();
q1.rdequeue();
q1.display();
}