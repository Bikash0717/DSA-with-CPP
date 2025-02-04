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
    node*p=new node;
    p=first;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void insertbegin(int x)
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

void insertend(int x)
{
if(avail==NULL)
{
cout<<"UNDERFLOW!"<<endl;
}
node* newnode=avail;

avail=avail->next;

newnode->data=x;


node *p=first;

while(p->next!=NULL)
{
    p=p->next;
}
cout<<x<<" is inserted at end!"<<endl;
newnode->next=NULL;
p->next=newnode;

}


void insertat(int pos,int x)
{
if(avail==NULL)
{
cout<<"UNDERFLOW!"<<endl;
}
node* newnode=avail;

avail=avail->next;

newnode->data=x;


node *p=first;
node *q=first;
for(int i=0;i<pos-1;i++)
{
    q=p;
    p=p->next;
    
}
cout<<x<<" is inserted at pos "<<pos<<endl;
newnode->next=p;
q->next=newnode;

}

void insertbefore(int value,int x)
{
if(avail==NULL)
{
cout<<"UNDERFLOW!"<<endl;
}
node* newnode=avail;

avail=avail->next;

newnode->data=x;


node *p=first;
node *q=first;
while(p->data!=value)
{
    q=p;
    p=p->next;
    
}
cout<<x<<" is inserted before "<<value<<endl;
newnode->next=p;
q->next=newnode;

}


void insertafter(int value,int x)
{
if(avail==NULL)
{
cout<<"UNDERFLOW!"<<endl;
}
node* newnode=avail;

avail=avail->next;

newnode->data=x;


node *p=first;

while(p->data!=value)
{
    p=p->next;
    
}
cout<<x<<" is inserted after "<<value<<endl;
newnode->next=p->next;
p->next=newnode;

}

int main()
{

create(7);
insertbegin(2);
insertbegin(4);

display();

insertend(8);
insertend(10);
insertat(3,12);
display();

insertbefore(8,17);
display();
insertafter(8,7);
display();

return 0;
}