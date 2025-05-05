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

    deletebegin();
   
    printList();

    deleteend();
    printList();

    deleteafter(40);
    printList();
    deletebefore(40);
    printList();

    return 0;
}
