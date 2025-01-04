
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* top = NULL;  
node* avail = NULL;  


void create(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        node* newNode = new node;  
        newNode->next = avail;     
        avail = newNode;         
    }
}


void push(int item) {
    if (avail == NULL) {
        cout << "Insert OVERFLOW!" << endl;
        
    }

    
    node* newnode = avail;
    avail = avail->next;  

   
    newnode->data = item;
    newnode->next = top;
    cout<<item<<"is pushed!"<<endl;

    
    top = newnode;
}
void printList() {
    node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void pop()
{
    if(top==NULL)
    {
        cout<<"UNDERFLOW!"<<endl;
    }
    node* ptr=top;
    cout<<top->data<<"is popped!"<<endl;
    top=top->next;
    ptr->next = avail;
    avail = ptr;
}
int main() {
    
    create(5);

    
    push(10);
    push(20);
    push(30);
    push(40);
    printList();
    pop();
    pop();
    printList();
}
  
