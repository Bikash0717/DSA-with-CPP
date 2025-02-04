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


void reverse()
{
    struct node *p=head;
    struct node *temp= new node;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->previous;
        p->previous=temp;
        p=p->previous;
        if(p!=NULL && p->next==NULL)
        {
            head=p;
        }
    }
}

int main()
{
int A[]={1,2,3,4,5};
create(A,5);
display();
reverse();
display();




return 0;
}