#include<iostream>
using namespace std;


struct node
{
    int data;
    node* next;
};
node *first=NULL;
node *avail=NULL;


void create(int n)
{
for(int i=0;i<n;i++)
{
node *newnode=new node;
newnode->next=avail;
avail=newnode;
}
}

void display()
{
    node*p=first;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void insert(int x)
{
if(avail==NULL)
{
cout<<"UNDERFLOW!"<<endl;
}
node* newnode=avail;
avail=avail->next;
newnode->data=x;
cout<<x<<" is inserted at begin!"<<endl;
newnode->next=first;
first=newnode;
}

void deletebegin()
{
    if(first==NULL)
    {
        cout<<"UNDERFLOW!";
        return;
    }
    node *ptr=first;
    first=first->next;
    cout<<"Node deleted from beginning!"<<endl;
    delete ptr;
}

void deleteend()
{
    if(first==NULL)
    {
        cout<<"UNDERFLOW!";
        return;
    }
    node *ptr=first;
    node *preptr=ptr;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;

    cout<<"Node deleted from end!"<<endl;
    delete ptr;
}

void deletespec(int value)
{
 if(first==NULL)
    {
        cout<<"UNDERFLOW!"<<endl;
        return;
    }
    node* ptr=first;
    while(ptr->data!=value)
    {
        ptr=ptr->next;
    }
    node* temp=ptr->next;
    ptr->next=temp->next;
    cout<<"Node deleted after "<<value<<endl;
    delete temp;
}

int main()
{

create(7);
insert(2);
insert(4);
insert(6);
insert(7);
display();

insert(8);
insert(10);
display();

deletebegin();
display();

deleteend();
display();

deletespec(8);
display();

return 0;
}