
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
    if(rear==SIZE-1)
    {
        cout<<"Overflow"<<endl;
        return;
    
    }
     
        if(front==-1)
    {
        front=rear=0;
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
   if(front==-1 || front>rear)
   {
    cout<<"underflow"<<endl;
    return;
   }
   else
   {
    cout<<"The dequeue item is:"<<QUEUE[front]<<endl;
    front++;

    if (front > rear) {
                front = rear = -1;
            }
   }
  }

void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << QUEUE[i] << " ";
            }
           
        }
    

}
};

int main()
{
   Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  

    q.display();

    q.dequeue();
    q.dequeue();


    q.display();

    return 0;
} 


