
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* start = NULL;  
node* avail = NULL;  


void create(int numNodes) {
    node* temp = NULL;
    for (int i = 0; i < numNodes; i++) {
        node* newNode = new node;  
        newNode->next = avail;  
        avail = newNode;          
    }
}


void insertbegin(int item) {
    if (avail == NULL) {
        cout << "Insert OVERFLOW!" << endl;
        return;
    }

   
    node* newnode = avail;
    avail = avail->next;  

    
    newnode->data = item;
    newnode->next = start;
    cout<<item<<"is inserted!"<<endl;

   
    start = newnode;
}



void insertend(int item) {
    if (avail == NULL) {
        cout << "Insert OVERFLOW!" << endl;
        return;
    }

    
    node* newnode = avail;
    avail = avail->next;  

   
    newnode->data = item;
    newnode->next = NULL;
    
    node* ptr=start;
    while(ptr->next!=0)
    {
        ptr=ptr->next;
    }
    cout<<item<<"is inserted!"<<endl;
    ptr->next=newnode;
   
    
}

void insertafter(int item,int num) {
    if (avail == NULL) {
        cout << "Insert OVERFLOW!" << endl;
        return;
    }

    
    node* newnode = avail;
    avail = avail->next; 


    newnode->data = item;

    node* ptr=start;
    node* preptr=ptr;
    while(preptr->data!=num)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    cout<<item<<"is inserted!"<<endl;
    preptr->next=newnode;
    newnode->next=ptr;
  
}

void insertbefore(int item,int num) {
    if (avail == NULL) {
        cout << "Insert OVERFLOW!" << endl;
        return;
    }

   
    node* newnode = avail;
    avail = avail->next;  

 
    newnode->data = item;

    node* ptr=start;
    node* preptr=ptr;
    while(ptr->data!=num)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    cout<<item<<"is inserted!"<<endl;
    preptr->next=newnode;
    newnode->next=ptr;
}


void printList() {
    node* temp = start;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
   
    create(5);

    
    insertbegin( 10);
    insertbegin( 20);
    insertend( 30);
  
    

    insertafter( 40,30);
    

    insertbefore( 50,30);
    insertbefore( 60,30);

    cout << "Linked List: ";
    printList();

    return 0;
}
