#include <iostream>
using namespace std;

#define MAX 5  

struct Node {
    int data;  
    int next;  
};

Node node[MAX];  
int front = -1, rear = -1, avail = 0;  


void initialize() {
    for (int i = 0; i < MAX - 1; i++) {
        node[i].next = i + 1;
    }
    node[MAX - 1].next = -1;  
}


int getNode() {
    if (avail == -1) {
        cout << "Queue is full!" << endl;
        return -1;
    } else {
        int index = avail;
        avail = node[avail].next;
        return index;
    }
}


void enqueue(int value) {
    int index = getNode();
    if (index == -1) return; 

    node[index].data = value;
    node[index].next = -1;  

   
    if (front == -1) {
        front = rear = index;
    } else {
        node[rear].next = index;  
        rear = index;  
    }

    cout << value << " is enqueued" << endl;
}


void dequeue() {
    if (front == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }

    int index = front;
    cout << node[index].data << " is dequeued" << endl;

    front = node[front].next;  
    if (front == -1) {
        rear = -1;  
    }
 
    node[index].next = avail;
    avail = index;
}


void display() {
    if (front == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }

    int i = front;
    cout << "Queue elements: ";
    while (i != -1) {
        cout << node[i].data << " ";
        i = node[i].next;
    }
    cout << endl;
}


int main() {
    initialize();  

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    
    enqueue(60);  


    dequeue();
    display();
    
    dequeue();
    display();
    

    enqueue(60);
    enqueue(70);
    display();

    return 0;
}
