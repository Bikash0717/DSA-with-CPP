#include<iostream>
using namespace std;


struct node
{
    int data;
    node* next;
};
node *first=NULL;
node *avail=NULL;

void create(int A[],int n)
{
int i;
struct node *t,*avail;
first=new node;
first->data=A[0];
first->next=NULL;
avail=first;

for(i=1;i<n;i++)
{
    t=new node;
    t->data=A[i];
    t->next=NULL;
    avail->next=t;
    avail=t;
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

node* search(node *p,int key)   //linear search
{
    
    
    while(p!=NULL)
    {
        if(p->data==key)
        {
            return p;
        }
        p=p->next;
    }
    return NULL; 
    
}

node* improved_search(node *p,int key)   //linear search
{
    
    struct node *q;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL; 
    
}


node* search_recur(node *p,int key)
{
    
    if(p==NULL)
    {
        return NULL;
    }
    if(key==p->data)
  {
    return p;
  }
  return search_recur(p->next,key);
}

int main()
{
struct node* temp;
int A[]={1,2,15,4,5};
create(A,5);
display();

temp=improved_search(first,15);
if(temp)
{
    cout<<temp->data<<" is found!"<<endl;
}
else
{
    cout<<temp->data<<" is not found!"<<endl;
}
display();

temp=improved_search(first,4);
if(temp)
{
    cout<<temp->data<<" is found!"<<endl;
}
else
{
    cout<<temp->data<<" is not found!"<<endl;
}
display();

return 0;
}