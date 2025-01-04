#include <iostream>
using namespace std;

struct node {
    int coeff;
    int exp;
    node* next;
};


node* create(int coeff, int exp) {
    node* newNode = new node; 
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}


void insert(node*& head, int coeff, int exp) {
    node* newnode = create(coeff, exp);
    if (head == NULL) {
        head = newnode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}


node* add(node* p, node* q) {
    node* r = NULL;  
    node* last = NULL ;  

    while (p != NULL && q != NULL) {
        node* temp = new node();  
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


void display(node* head) {
    node* temp = head;
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

int main() {
    node* p = NULL;  
    node* q = NULL;  

    int n1, n2, coeff, exp;

    cout << "Enter the number of terms in the first polynomial: ";
    cin >> n1;

    for (int i = 0; i < n1; i++) {
        cout << "Enter the coefficient and exponent for term " << i + 1 << ": ";
        cin >> coeff >> exp;
        insert(p, coeff, exp);
    }

    cout << "Enter the number of terms in the second polynomial: ";
    cin >> n2;

    for (int i = 0; i < n2; i++) {
        cout << "Enter the coefficient and exponent for term " << i + 1 << ": ";
        cin >> coeff >> exp;
        insert(q, coeff, exp);
    }

    cout << "First polynomial: ";
    display(p);

    cout << "Second polynomial: ";
    display(q);

 
    node* result = add(p, q);

   
    cout << "Sum of the polynomials: ";
    display(result);

    return 0;
}
