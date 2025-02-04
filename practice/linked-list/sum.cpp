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

int sum()
{
    int sums=0;
    node *p=first;
    while(p!=NULL)
    {
        sums+=p->data;
        p=p->next;
    }
    return sums;
}

int main()
{
int A[]={1,2,3,4,5};
create(A,5);
display();

cout<<"The sum is: "<<sum();

return 0;
}