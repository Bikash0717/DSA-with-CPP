
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* start = NULL;  
node* avail = NULL;  


void create(int numNodes) {
   
    for (int i = 0; i < numNodes; i++) {
        node* newNode = new node;  
        newNode->next = avail;     
        avail = newNode;           
    }
}

void insert(int item) {
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

void deletebegin()
{
    if(start==NULL)
    {
        cout<<"UNDERFLOW!"<<endl;
    }
    node* ptr=start;
    cout<<start->data<<"is deleted!"<<endl;
    start=start->next;
    delete ptr;
}

void deleteend()
{
    if(start==NULL)
    {
        cout<<"UNDERFLOW!"<<endl;
    }
    node* ptr=start;
    node* preptr=ptr;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    cout<<ptr->data<<"is deleted!"<<endl;
    preptr->next=NULL;
    delete ptr;
}

void deletespec(int num)
{
 if(start==NULL)
    {
        cout<<"UNDERFLOW!"<<endl;
    }
    node* ptr=start;
    node* preptr=ptr;
    while(preptr->data!=num)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    node* temp=ptr;
    preptr->next=ptr->next;
    delete temp;
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

    deletespec(30);
    
    printList();


    return 0;
}
