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
newnode->next=first;
first=newnode;
}

void removedublicate()
{
    node* p=first;
    node* q=first->next;
    while (p->next != NULL) {
        if (p->data ==q->data) {
            
          
            p->next = q->next;
            delete q;
        } else {
        
            p = p->next;
        }
    }
}


int main()
{
create(5);
insert(10);
insert(9);
insert(8);
insert(7);
insert(7);
display();
removedublicate();
display();
return 0;
}