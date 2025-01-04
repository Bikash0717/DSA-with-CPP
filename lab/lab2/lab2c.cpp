

#include<iostream>
#define SIZE 7
using namespace std;

class Queue
{
    int rear, front;
    int QUEUE[SIZE];
public:
    Queue()
    {
        front = rear = -1;  
    }

    void fenqueue(int item)  
    {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) 
        {
            cout << "Front Overflow" << endl;
        }
        else
        {
            if (front == -1)  
            {
                front = 0;
                rear = 0;
            }
            else if (front == 0)  
            {
                front = SIZE - 1;
            }
            else  
            {
                front--;
            }
            QUEUE[front] = item;  
            cout << item << " is inserted at the front" << endl;
        }
    }

    void renqueue(int item)  
    {
        if ((rear == SIZE - 1 && front == 0) || (rear == front - 1))  
        {
            cout << "Overflow" << endl;
        }
        else
        {
            if (front == -1) 
            {
                front = 0;
                rear = 0;
            }
            else if (rear == SIZE - 1)  
            {
                rear = 0;
            }
            else
            {
                rear++;  
            }
            QUEUE[rear] = item;  
            cout << item << " is inserted at the rear" << endl;
        }
    }

    void fdequeue()  
    {
        if (front == -1)  
        {
            cout << "Underflow" << endl;
        }
        else
        {
            int item = QUEUE[front];
            cout << item << " is dequeued from the front" << endl;
            if (front == rear)  
            {
                front = rear = -1; 
            }
            else if (front == SIZE - 1)  
            {
                front = 0;
            }
            else
            {
                front++;  
            }
        }
    }

    void rdequeue()  
    {
        if (front == -1)  
        {
            cout << "Underflow" << endl;
        }
        else
        {
            int item = QUEUE[rear];
            cout << item << " is dequeued from the rear" << endl;
            if (front == rear)  
            {
                front = rear = -1; 
            }
            else if (rear == 0)  
            {
                rear = SIZE - 1;
            }
            else
            {
                rear--;  
            }
        }
    }

    void display()  
    {
        if (front == -1)  
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        if (front <= rear)  
        {
            for (int i = front; i <= rear; i++)
            {
                cout << QUEUE[i] << " ";
            }
        }
        else  
        {
            for (int i = front; i < SIZE; i++)
            {
                cout << QUEUE[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << QUEUE[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    Queue q;


    
    q.renqueue(30);
    q.renqueue(40);
    q.display();

    q.fenqueue(10);
    q.fenqueue(20);
    q.display();

    
    q.fdequeue();
    q.fdequeue();
    q.display();
    q.rdequeue();
    q.rdequeue();

    
    q.display();

    return 0;
}
