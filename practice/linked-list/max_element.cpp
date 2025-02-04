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

int maxx()
{
    
    node *p=first;
    int max=-32768;
    while(p!=NULL)
    {
         if(max<p->data)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}


int max_recur(node *p)
{
    int x=0;
    if(p==0)
    {
        return x;
    }
    else
    {
        x=max_recur(p->next);
        if(x>p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}

int main()
{
int A[]={1,2,15,4,5};
create(A,5);
display();

cout<<"The max element is: "<<max_recur(first);

return 0;
}