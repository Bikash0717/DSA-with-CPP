#include<iostream>
using namespace std;


struct Node
{
    int coeff;
    int exp;
    Node *next;
};



Node* create(int coeff, int exp) {
    Node* newNode = new Node; 
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insert(Node*& head,int coeff,int exp)
{
Node *newNode=create(coeff,exp);
if(head==NULL)
{
    head=newNode;
}
else
{
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
}



Node* add(Node* p, Node* q) {
    Node* r = NULL;  
    Node* last = NULL ;  

    while (p != NULL && q != NULL) {
        Node* temp = new Node;  
        temp->next = NULL; 

        if (p->exp > q->exp) {
            temp->coeff = p->coeff;
            temp->exp = p->exp;
            p = p->next;
        } else if (p->exp < q->exp) {
            temp->coeff = q->coeff;
            temp->exp = q->exp;
            q = q->next;
        } else {
            temp->coeff = p->coeff + q->coeff;
            temp->exp = p->exp;
            p = p->next;
            q = q->next;
        }

        if (r == NULL) {
            r = temp;
            last = r;
        } else {
            last->next = temp;
            last = temp;
        }
    }


    return r;
}


void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->exp == 0)
            cout << temp->coeff;
        else
            cout << temp->coeff << "x^" << temp->exp;
        if (temp->next != NULL && temp->next->coeff > 0)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
Node *p=NULL;
Node *q=NULL;

int n1,n2,coeff,exp;

cout<<"Enter the no of terms in the first polynomial: ";
cin>>n1;

for(int i=0;i<n1;i++)
{
    cout<<"Enter the coefficient and exponent for term "<<i+1<<":";
    cin>>coeff>>exp;
    insert(p,coeff,exp);
}

cout<<"Enter the no of terms in the second polynomial: ";
cin>>n2;

for(int i=0;i<n2;i++)
{
    cout<<"Enter the coefficient and exponent for term "<<i+1<<":";
    cin>>coeff>>exp;
    insert(q,coeff,exp);
}

cout << "First polynomial: ";
    display(p);

    cout << "Second polynomial: ";
    display(q);

 
    Node* result = add(p, q);

   
    cout << "Sum of the polynomials: ";
    display(result);

    return 0;
}