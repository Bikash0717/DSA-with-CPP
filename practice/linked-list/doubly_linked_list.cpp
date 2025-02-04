#include<iostream>
using namespace std;


struct node
{
    int data;
    node* next;
    node* previous;
};
node *head=NULL;


void create(int A[],int n)
{
int i;
struct node *t,*last;
head=new node;
head->data=A[0];
head->next=NULL;
head->previous=NULL;
last=head;


for(i=1;i<n;i++)
{
    t=new node;
    t->data=A[i];
    t->next=NULL;
    t->previous=last;
    last->next=t;
    last=t;
    
}
}


void display()
{
    node*p=head;

    do
    {
        cout<<p->data<<" ";
        p=p->next;
    } 
    
    while(p!=NULL);
    cout<<endl;
}


void insertbegin(int num)
{
    node *newnode=new node;
    newnode->data=num;
    newnode->next=head;
    newnode->previous=NULL;
    head=newnode;
    cout<<num<<" is inserted at beginning!"<<endl;

}

void insertend(int num)
{
    node *newnode=new node;
    newnode->data=num;
    newnode->next=NULL;
    cout<<num<<" is inserted at end!"<<endl;
node *p=head;

while(p->next!=NULL)
{
p=p->next;
}
p->next=newnode;
newnode->previous=p;
}


void insertpos(int index,int num)
{
    node *newnode=new node;
    newnode->data=num;
  
    cout<<num<<" is inserted at pos "<<index<<endl;
node *p=head;

for(int i=1;i<index-1;i++)
{
p=p->next;
}
newnode->next=p->next;
p->next=newnode;
newnode->previous=p;

}


void insertbefore(int value,int num)
{
    node *newnode=new node;
    newnode->data=num;
  
    cout<<num<<" is inserted at before"<<value<<endl;
node *p=head;

while(p->next->data!=value)
{
p=p->next;
}
newnode->next=p->next;
newnode->previous=p;
p->next=newnode;
p->next->previous=newnode;

}

void insertafter(int value,int num)
{
    node *newnode=new node;
    newnode->data=num;
  
    cout<<num<<" is inserted after!"<<value<<endl;
node *p=head;

while(p->data!=value)
{
p=p->next;
}
newnode->next=p->next;
newnode->previous=p;
p->next=newnode;
p->next->previous=newnode;

}


void deletebegin()
{

    cout<<"Node deleted at beginning!"<<endl;
    node *p=head;
node *temp=head;
p=head->next;
head=head->next;

p->previous=NULL;
delete temp;
}

void deleteend()
{

    cout<<" Node deleted at end!"<<endl;
    node *p=head;

while(p->next->next!=NULL)
{
p=p->next;
}
node *temp = p->next;
p->next = NULL;
delete temp;
}

void deletepos(int index)
{

    cout<<" Node deleted at pos !"<<index<<endl;
    node *p=head;
for(int i=0;i<index-1;i++)
{
p=p->next;
}

node *temp=p;
p->previous->next=p->next;
p->next->previous=p->previous;
p=p->next;
delete temp;
}

void deletebefore(int value)
{

    cout<<" Node deleted before !"<<value<<endl;
    node *p=head;
while(p->next->data!=value)
{
p=p->next;
}

node *temp=p;
p->previous->next=p->next;
p->next->previous=p->previous;
delete temp;
}


void deleteafter(int value)
{

    cout<<" deleted after !"<<value<<endl;
    node *p=head;
   
while(p->data!=value)
{
p=p->next;
}

node *temp=p->next;
p->next=p->next->next;
p->next->previous=p;
delete temp;
}

int main()
{
int A[]={1,2};
create(A,2);
display();

insertbegin(3);
insertbegin(4);
display();

insertend(6);
display();

insertpos(3,7);
display();

insertbefore(2,8);
display();


insertafter(2,10);
display();



deletebegin();
display();

deleteend();
display();

deletepos(2);
display();


deleteafter(1);
display();

deletebefore(10);
display();

/* deletepos(2);
display();

deletebegin();
display();

deleteend();
display();

deletebefore(10);
display();

deleteafter(8);
display(); */
return 0;
}