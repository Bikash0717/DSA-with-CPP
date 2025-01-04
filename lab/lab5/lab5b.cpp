
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* previous;
};

node* start = NULL;  
node* avail = NULL; 


void create(int numNodes) {
     for (int i = 0; i < numNodes; i++) {
        node* newNode = new node; 
        newNode->next = avail;    
        newNode->previous = NULL;
        avail = newNode;           
    }
}

void insert(int item) {
    if (avail == NULL) {
        cout << "OVERFLOW!" << endl;
        return;
    }

   
    node* newnode = avail;
    avail = avail->next;  

    
    newnode->data = item;
    newnode->next = start;
    newnode->previous = NULL;

    if (start != NULL) {
        start->previous = newnode;
    }

    cout << item << " is inserted!" << endl;

    
    start = newnode;
}

void deletebegin()
{
    if(start==NULL)
    {
        cout<<"UNDERFLOW!"<<endl;
    }
    node* ptr=start;
    cout<<"Node is deleted from beginning!"<<endl;
    start=start->next;
    start->previous=NULL;
    delete ptr;
}

void deleteend()
{
    if (start == NULL) {
        cout << "UNDERFLOW!" << endl;
        return;
    }

    
    node* temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }

   
    if (temp->previous != NULL) {
        temp->previous->next = NULL;
    } else {
        start = NULL;  
    }

    temp->next = avail;
    temp->previous = NULL;
    avail = temp;

    cout << "Node deleted from the end!" << endl;

}

void deleteafter(int num)
{
 if (start == NULL) {
        cout << "UNDERFLOW!" << endl;
        return;
    }

  
    node* ptr = start;
    while (ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL) {
        cout << "No node exists after the value " << num << "!" << endl;
        return;
    }

    
    node* temp = ptr->next;
    ptr->next = temp->next;

    if (temp->next != NULL) {
        temp->next->previous = ptr;
    }

 
    temp->next = avail;
    temp->previous = NULL;
    avail = temp;

    cout << "Node after " << num << " deleted!" << endl;

}

void deletebefore(int num) {
    if (start == NULL || start->next == NULL) {
        cout << "UNDERFLOW!" << endl;
        return;
    }

    node* ptr = start;
    while (ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->previous == NULL) {
        cout << "No node exists before the value " << num << "!" << endl;
        return;
    }

   
    node* temp = ptr->previous;
    ptr->previous = temp->previous;
    if (temp->previous != NULL) {
        temp->previous->next = ptr;
    } else {
        start = ptr;  
    }
    

   
    temp->next = avail;
    temp->previous = NULL;
    avail = temp;

    cout << "Node before " << num << " deleted!" << endl;
}


void printList() {
    node* temp = start;
     cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    
    create(6);

    
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
  
    printList();

    deletebegin();
    deletebegin();
    printList();

    deleteend();
    printList();

    deleteafter(30);
    printList();
    deletebefore(30);
    printList();


    return 0;
}
