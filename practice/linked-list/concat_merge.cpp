#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node *first = NULL;
node *second = NULL;
node *third = NULL;
node *fourth = NULL;

void create(int A[], int n) {
    node *last, *t;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int B[], int n) {
    node *last, *t;
    second = new node;
    second->data = B[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++) {
        t = new node;
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void concat(node *p, node *q) {
    third = p;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = q;
}

void merge(node *p, node *q) {
    node *last;

    if (p->data < q->data) {
        fourth = last = p;
        p = p->next;
    } else if(p->data>q->data){
        fourth = last = q;
        q = q->next;
    }
    else
    {
       fourth = last = p;
        p = p->next;
        q=q->next; 
    }
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
        } 
        else if(p->data>q->data)
         {
            last->next = q;
            last = q;
            q = q->next;
        }
        else
        {
           last->next = p;
            last = p;
            p = p->next; 
            q=q->next;
        }
    }

    if (p != NULL) last->next = p;
    if (q != NULL) last->next = q;
}

int main() {
    int A[] = {1, 3, 4, 5};
    int B[] = {2, 4, 6, 8, 10};

    create(A, 4);
    display(first);

    create2(B, 5);
    display(second);

    concat(first, second);
    display(third);

    create(A, 4);
    create2(B, 5);

    merge(first, second);
    display(fourth);

    return 0;
}
