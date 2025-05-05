#include<iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
};
Node *start=NULL;
Node *avail=NULL;


void create(int num)
{
    for(int i=0;i<num;i++)
    {
        Node *newnode=new Node;
        newnode->next=avail;
        avail=newnode;
     
    }
}

void insertbegin(int num)
{


if(avail==NULL)
{
    cout<<"OVERFLOW!"<<endl;
    return;
}

Node *newnode=avail;
avail=avail->next;
cout<<num<<" is inserted!"<<endl;
newnode->data=num;
newnode->next=start;
start=newnode;

}


void insertend(int num)
{
    if(avail==NULL)
    {
        cout<<"OVERFLOW!"<<endl;
        return;
    }

    Node *newnode=avail;
    avail=avail->next;


    newnode->data=num;
    newnode->next=NULL;

Node *ptr=start;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
cout<<num<<" is inserted!"<<endl;
ptr->next=newnode;


}

void insertafter(int value,int num)
{

    if(avail==NULL)
    {
        cout<<"OVERFLOW!"<<endl;
        return;
    }

    Node *newnode=avail;
    avail=avail->next;
    
newnode->data=num;

Node *ptr=start;
Node *preptr=ptr;
while(preptr->data!=value)
{
    preptr=ptr;
ptr=ptr->next;
}

cout<<num<<" is inserted after "<<value<<endl;
preptr->next=newnode;
newnode->next=ptr;
}

void insertbefore(int value,int num)
{

    if(avail==NULL)
    {
        cout<<"OVERFLOW!"<<endl;
        return;
    }

    

    Node *newnode=avail;
    avail=avail->next;
newnode->data=num;
if (start->data == value) {
    // Insert at the beginning if value is at the start
    newnode->next = start;
    start = newnode;
    cout << num << " is inserted before " << value << endl;
    return;
}
Node *ptr=start;
Node *preptr=ptr;
while(ptr->data!=value)
{
ptr=ptr->next;
}

cout<<num<<" is inserted before "<<value<<endl;

preptr->next=newnode;
newnode->next=ptr;
}


void deletebegin()
{
    if(start==NULL)
    {
        cout<<"UNDERFLOW!"<<endl;
    }
    
    Node *ptr=start;
    cout<<ptr->data<<" is deleted!"<<endl;
    start=start->next;
    delete ptr;
}

void deleteend()
{
    if(start==NULL)
    {
        cout<<"UNDERFLOW!"<<endl;
    }
    
    Node *ptr=start;
    Node *preptr=ptr;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    Node *temp=ptr;
    cout<<temp->data<<" is deleted!"<<endl;
   preptr->next=NULL;
    delete temp;
}
void deleteafter(int value)
{
    if(start==NULL)
    {
        cout<<"UNDERFLOW!"<<endl;
    }
    
    Node *ptr=start;
    Node *preptr=ptr;
    while(preptr->data!=value)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    Node *temp=ptr;
    cout<<temp->data<<" is deleted!"<<endl;
   preptr->next=ptr->next;
    delete temp;
}

void deletebefore(int value)
{
    if(start==NULL)
    {
        cout<<"UNDERFLOW!"<<endl;
    }
    
    Node *ptr=start;
    Node *preptr=ptr;
    while(ptr->next->data!=value)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    Node *temp=ptr;
    cout<<temp->data<<" is deleted!"<<endl;
   preptr->next=ptr->next;
    delete temp;
}

void display()
{
    Node *ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main()
{
create(7);
insertbegin(3);
insertend(4);

display();

insertbefore(3,5);
display();
insertafter(3,6);
insertbegin(8);
insertbegin(9);
insertbegin(0);
display();

deletebegin();
deleteend();
deleteafter(3);
deletebefore(3);
display();
}