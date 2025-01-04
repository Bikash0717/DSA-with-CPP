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


void insertbegin(int item) {
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

    cout << item << " is inserted at the beginning!" << endl;

    
    start = newnode;
}


void insertend(int item) {
    if (avail == NULL) {
        cout << "OVERFLOW!" << endl;
        return;
    }

   
    node* newnode = avail;
    avail = avail->next;  

  
    newnode->data = item;
    newnode->next = NULL;
    newnode->previous = NULL;

    if (start == NULL) {
        start = newnode;
    } else {
        node* ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->previous = ptr;
    }
    cout << item << " is inserted at end!" << endl;
}


void insertafter(int item, int num) {
    if (avail == NULL) {
        cout << "OVERFLOW!" << endl;
        return;
    }

    
    node* newnode = avail;
    avail = avail->next;  

    
    newnode->data = item;

    node* ptr = start;

    
    while (ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Node with value " << num << " not found!" << endl;
    }

    newnode->next = ptr->next;
    newnode->previous = ptr;

    if (ptr->next != NULL) {
        ptr->next->previous = newnode;
    }

    ptr->next = newnode;

    cout << item << " is inserted after " << num << endl;
}


void insertbefore(int item, int num) {
    if (avail == NULL) {
        cout << "OVERFLOW!" << endl;
        return;
    }

   
    node* newnode = avail;
    avail = avail->next;  

   
    newnode->data = item;

    node* ptr = start;

   
    while (ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Node with value " << num << " not found!" << endl;
        return;
    }

    newnode->next = ptr;
    newnode->previous = ptr->previous;

    if (ptr->previous != NULL) {
        ptr->previous->next = newnode;
    } else {
        start = newnode;
    }

    ptr->previous = newnode;

    cout << item << " is inserted before " << num << endl;
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

    
    insertbegin(10);
    insertbegin(20);
    insertend(30);

    insertafter(40, 10);

    insertbefore(50, 30);
    insertbefore(60, 30);

    
    cout << "Linked List: ";
    printList();

    return 0;
}
