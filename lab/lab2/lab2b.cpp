#include<iostream>
#define SIZE 5
using namespace std;


class Queue
{
    int rear,front;
    int QUEUE[SIZE];
public:
  Queue()
  {
   front=rear=-1;
  }

  void enqueue(int item)
  {
    if((front ==0 && rear==SIZE-1)||(front==rear+1))
    {
        cout<<"Overflow"<<endl;
        return;
    }
     
      else if(front==-1)
    {
        front=rear=0;
    }

    else if(rear==SIZE-1 && front!=0)
    {
      rear=0;
    }
      else
      {
        rear++;
      }
        QUEUE[rear]=item;
        cout<<item<<"is inserted"<<endl;
  }
  

  void dequeue()
  {
   if(front==-1)
   {
    cout<<"underflow"<<endl;
    return;
   }
    cout<<"The dequeue item is:"<<QUEUE[front]<<endl;

    if (front == rear) {
                front = rear = -1;
            }
            else if(front==SIZE-1)
            {
                front=0;
            }
            else
            {
                front++;
            }
   }
  

void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                cout << QUEUE[i] << " ";
            }
        } else {
            // Wrap around case (front > rear)
            for (int i = front; i < SIZE; i++) {
                cout << QUEUE[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << QUEUE[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
   Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    

    
    q.display();

    
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(50);
    q.enqueue(60);


    q.display();

    return 0;
} 


