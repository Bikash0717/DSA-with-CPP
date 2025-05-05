#include<iostream>
using namespace std;
#define MAX 5

struct Node
{
    int data;
    int next;
};
Node node[MAX];
int avail=0,list=-1;

void initialize()
{
    for(int i=0;i<MAX;i++)
    {
        node[i].next=i+1;
    }
    node[MAX-1].next=-1;
}

int getnode()
{
    if(avail==-1)
    {
        cout<<"List is full!"<<endl;
        return -1;
    }
    else
    {
        int index=avail;
        avail=node[avail].next;
        return index;
    }
}

void insertbegin(int x)
{
    int index=getnode();
    if(index==-1) return;
    node[index].data=x;
    cout<<x<<" is inserted at beginnning!"<<endl;
    node[index].next=list;
    list=index;
}

void insertend(int x)
{
    int index=getnode();
    if(index==-1) return;
    node[index].data=x;
    node[index].next=-1;

    cout<<x<<" is inserted at end!"<<endl;

    if(list==-1)
    {
        list=index;
    }
    else
    {
        int i=list;
        while(node[i].next!=-1)
        {
            i=node[i].next;
        }
        node[i].next=index;
    }
}

void insertafter(int value,int x)
{
    int i=list;
    while(node[i].data!=value)
    {
        i=node[i].next;
    }
    int index=getnode();
    if(index==-1) return;
    node[index].data=x;
    cout<<x<<" is inserted at after "<<value<<endl;
    node[index].next=node[i].next;
    node[i].next=index;
}

void display()
{
    int i=list;
    while(i!=-1)
    {
        cout<<node[i].data<<" ";
        i=node[i].next;
    }
    cout<<endl;
}

void freenode(int index)
{
    node[index].next=avail;
    avail=index;
    if(index==list)
    {
        list=-1;
    }
}

void deletebegin()
{
    if(list==-1)
    {
        cout<<"List is empty!"<<endl;
    }
    int index=list;
    cout<<node[index].data<<" is deleted from beginnning"<<endl;
    list=node[list].next;
    freenode(index);
}

void deleteend()
{
    if(list==-1)
    {
        cout<<"list is empty!"<<endl;
    }
    int index=list,prev=-1;

    while(node[index].next!=-1)
    {
        prev=index;
        index=node[index].next;
    }
    cout<<node[index].data<<" is deleted from end!"<<endl;
    if(prev==-1)
    {
        list=-1;
    }
    else
    {
        node[prev].next=-1;
    }
    freenode(index);
}

void deleteafter(int value)
{
    if(list==-1)
    {
        cout<<"List is empty!"<<endl;
    }
    int index=list;

    while(node[index].data!=value)
    {
        index=node[index].next;
    }
    int del=node[index].next;
    cout<<node[del].data<<" is deleted after "<<value<<endl;
    node[index].next=node[del].next;
    
    freenode(del);
}

int main()
{
    initialize();
    insertbegin(10);
    insertbegin(20);
    insertend(30);
    display();
    insertafter(20, 25);
    display();
    insertend(50);
    display();

    deletebegin();
    display();

    deleteafter(25);
    display();

    deleteend();
    display();

    insertbegin(10);
    insertbegin(20);
    display();
   
    return 0;
}