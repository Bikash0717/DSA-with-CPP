
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* front = NULL;  
node* rear = NULL;  


void create(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        node* newNode = new node;  
        newNode->next = rear;    
        rear = newNode;     
       
    }
}


void enqueue(int item) {

   if (rear == NULL) {
        cout << "OVERFLOW!" << endl;
        return;
    }

    
    node* newnode = rear;
    rear = rear->next;  

    
    newnode->data = item;
    newnode->next = front;
    cout<<item<<" is enqueued!"<<endl;

    
    front = newnode;

    
}
void printList() {
    node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void dequeue()
{
    if(front==NULL)
    {
        cout<<"UNDERFLOW!"<<endl;
    }
    node* ptr=front;
    node* preptr=ptr;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    cout<<ptr->data<<" is dequeued!"<<endl;
    preptr->next=NULL;
    ptr->next = rear;
    rear = ptr;
}
int main() {
  
    create(5);

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printList();
    dequeue();
    dequeue();
    printList();
}
  










