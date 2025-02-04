#include<iostream>
using namespace std;


struct node
{
    int data;
    node* next;
};
node *head=NULL;


void create(int A[],int n)
{
int i;
struct node *t,*last;
head=new node;
head->data=A[0];
head->next=head;
last=head;


for(i=1;i<n;i++)
{
    t=new node;
    t->data=A[i];
    t->next=head;
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
    
    while(p!=head);
    cout<<endl;
}


void insertbegin(int num)
{
    node *newnode=new node;
    newnode->data=num;
    newnode->next=head;
    cout<<num<<" is inserted at beginning!"<<endl;
node *p=head;

while(p->next!=head)
{
p=p->next;
}
p->next=newnode;
head=newnode;
}

void insertend(int num)
{
    node *newnode=new node;
    newnode->data=num;
    newnode->next=head;
    cout<<num<<" is inserted at end!"<<endl;
node *p=head;

while(p->next!=head)
{
p=p->next;
}
p->next=newnode;
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
p->next=newnode;

}

void insertafter(int value,int num)
{
    node *newnode=new node;
    newnode->data=num;
  
    cout<<num<<" is inserted after!"<<value<<endl;
node *p=head;

while(p->next->data!=value)
{
p=p->next;
}
p=p->next;
newnode->next=p->next;
p->next=newnode;

}


void deletebegin()
{

    cout<<"Node deleted at beginning!"<<endl;
    node *p=head;

while(p->next!=head)
{
p=p->next;
}
p->next=head->next;
node *temp=head;
head=head->next;
delete temp;
}

void deleteend()
{

    cout<<" Node deleted at end!"<<endl;
    node *p=head;

while(p->next->next!=head)
{
p=p->next;
}
node *temp = p->next;
p->next = head;
delete temp;
}

void deletepos(int index)
{

    cout<<" Node deleted at pos !"<<index<<endl;
    node *p=head;
    node *prep=head;
for(int i=0;i<index-1;i++)
{
prep=p;
p=p->next;
}
prep->next=p->next;

node *temp=p;
p=p->next;
delete temp;
}

void deletebefore(int value)
{

    cout<<" Node deleted before !"<<value<<endl;
    node *p=head;
    node *prep=head;
while(p->next->data!=value)
{
    prep=p;
p=p->next;
}
prep->next=p->next;
node *temp=p;
p=p->next;
delete temp;
}


void deleteafter(int value)
{

    cout<<" deleted after !"<<value<<endl;
    node *p=head;
    node *prep=head;
while(prep->data!=value)
{
prep=p;
p=p->next;
}
prep->next=p->next;

node *temp=p;
p=p->next;
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

deletepos(4);
display();

deletebegin();
display();

deleteend();
display();

deletebefore(10);
display();

deleteafter(8);
display();
return 0;
}