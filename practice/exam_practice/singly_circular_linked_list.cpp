#include<iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
};
Node *start=NULL;
Node *avail=NULL;


void create(int num)
{
    for(int i=0;i<num;i++)
    {
        Node *newnode=new Node;
        newnode->next=avail;
        avail=newnode;
     
    }
}


void display()
{
    if (start == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    Node *ptr = start;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != start);
    cout << endl;
}

void insertbegin(int num)
{
    if (avail == NULL)
    {
        cout << "OVERFLOW!" << endl;
        return;
    }

    Node *newnode = avail;
    avail = avail->next;
    cout << num << " is inserted!" << endl;
    newnode->data = num;

    if (start == NULL)
    {
        newnode->next = newnode;
        start = newnode;
    }
    else
    {
        Node *ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        newnode->next = start;
        ptr->next = newnode;
        start = newnode;
    }
}

void insertend(int num)
{
    if (avail == NULL)
    {
        cout << "OVERFLOW!" << endl;
        return;
    }

    Node *newnode = avail;
    avail = avail->next;
    newnode->data = num;

    if (start == NULL)
    {
        newnode->next = newnode;
        start = newnode;
    }
    else
    {
        Node *ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        newnode->next = start;
        ptr->next = newnode;
    }
    cout << num << " is inserted!" << endl;
}

void deletebegin()
{
    if (start == NULL)
    {
        cout << "UNDERFLOW!" << endl;
        return;
    }

    Node *ptr = start;

    if (start->next == start)
    {
        cout << start->data << " is deleted!" << endl;
        delete start;
        start = NULL;
        return;
    }

    while (ptr->next != start)
    {
        ptr = ptr->next;
    }

    cout << start->data << " is deleted!" << endl;
    Node *temp = start;
    start = start->next;
    ptr->next = start;
    delete temp;
}

void deleteend()
{
    if (start == NULL)
    {
        cout << "UNDERFLOW!" << endl;
        return;
    }

    Node *ptr = start;
    Node *preptr = NULL;

    if (start->next == start)
    {
        cout << start->data << " is deleted!" << endl;
        delete start;
        start = NULL;
        return;
    }

    while (ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    cout << ptr->data << " is deleted!" << endl;
    preptr->next = start;
    delete ptr;
}


int main()
{
create(7);
insertbegin(3);
insertend(4);

display();


insertbegin(8);
insertend(9);
insertend(0);
display();

deletebegin();
deleteend();

display();
}