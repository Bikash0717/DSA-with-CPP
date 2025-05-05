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
        
        s[++top]=value;
      
        
    }
    
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        
        return s[top--];
       
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


class Queue
{
    private:
    Stack stack1;
    Stack stack2;

    public:
    Queue(int size):stack1(size),stack2(size){}
   
   void enqueue(int value)
   {
    cout<<"Enqueued:"<<value<<endl;
    stack1.push(value);
   }

   int dequeue()
   {
    if(stack2.isEmpty())
    {
        if(stack1.isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else
        {
            while(!stack1.isEmpty())
            {
                stack2.push(stack1.pop());
            }
        }

    }
    return stack2.pop();
   }
};


int main()
{
Queue q(5);
q.enqueue(3);
q.enqueue(4);
q.enqueue(5);

  cout << "Dequeued: " << q.dequeue() << endl;  // 10
    cout << "Dequeued: " << q.dequeue() << endl;



}