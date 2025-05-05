#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* previous;
};

node* start = NULL;
node* avail = NULL;

void create(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        node* newNode = new node;
        newNode->next = avail;
        newNode->previous = NULL;
        avail = newNode;
    }
}

void insertbegin(int item) {
    if (avail == NULL) {
        cout << "OVERFLOW!" << endl;
        return;
    }

    node* newnode = avail;
    avail = avail->next;

    newnode->data = item;
    if (start == NULL) {
        start = newnode;
        start->next = start;
        start->previous = start;
    } else {
        node* last = start->previous;
        newnode->next = start;
        newnode->previous = last;
        start->previous = newnode;
        last->next = newnode;
        start = newnode;
    }

    cout << item << " is inserted at the beginning!" << endl;
}

void insertend(int item) {
    if (avail == NULL) {
        cout << "OVERFLOW!" << endl;
        return;
    }

    node* newnode = avail;
    avail = avail->next;

    newnode->data = item;
    if (start == NULL) {
        start = newnode;
        start->next = start;
        start->previous = start;
    } else {
        node* last = start->previous;
        newnode->next = start;
        newnode->previous = last;
        start->previous = newnode;
        last->next = newnode;
    }

    cout << item << " is inserted at the end!" << endl;
}

void insertafter(int item, int num) {
    if (avail == NULL) {
        cout << "OVERFLOW!" << endl;
        return;
    }

    node* newnode = avail;
    avail = avail->next;

    newnode->data = item;

    node* ptr = start;
    while (ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Node with value " << num << " not found!" << endl;
        return;
    }

    newnode->next = ptr->next;
    newnode->previous = ptr;

    if (ptr->next != NULL) {
        ptr->next->previous = newnode;
    }

    ptr->next = newnode;

    cout << item << " is inserted after " << num << endl;
}

void insertbefore(int item, int num) {
    if (avail == NULL) {
        cout << "OVERFLOW!" << endl;
        return;
    }

    node* newnode = avail;
    avail = avail->next;

    newnode->data = item;

    node* ptr = start;

    while (ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Node with value " << num << " not found!" << endl;
        return;
    }

    newnode->next = ptr;
    newnode->previous = ptr->previous;

    if (ptr->previous != NULL) {
        ptr->previous->next = newnode;
    } else {
        start = newnode;
    }

    ptr->previous = newnode;

    cout << item << " is inserted before " << num << endl;
}

void deletebegin() {
    if (start == NULL) {
        cout << "UNDERFLOW!" << endl;
        return;
    }

    if (start->next == start) {
        delete start;
        start = NULL;
    } else {
        node* last = start->previous;
        start = start->next;
        start->previous = last;
        last->next = start;
        delete start->previous;
    }

    cout << "Node is deleted from the beginning!" << endl;
}

void deleteend() {
    if (start == NULL) {
        cout << "UNDERFLOW!" << endl;
        return;
    }

    if (start->next == start) {
        delete start;
        start = NULL;
    } else {
        node* last = start->previous;
        last->previous->next = start;
        start->previous = last->previous;
        delete last;
    }

    cout << "Node deleted from the end!" << endl;
}

void deleteafter(int num) {
    if (start == NULL) {
        cout << "UNDERFLOW!" << endl;
        return;
    }

    node* ptr = start;
    while (ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == start) {
        cout << "No node exists after the value " << num << "!" << endl;
        return;
    }

    node* temp = ptr->next;
    ptr->next = temp->next;
    temp->next->previous = ptr;

    delete temp;

    cout << "Node after " << num << " deleted!" << endl;
}

void deletebefore(int num) {
    if (start == NULL || start->next == start) {
        cout << "UNDERFLOW!" << endl;
        return;
    }

    node* ptr = start;
    while (ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->previous == start) {
        cout << "No node exists before the value " << num << "!" << endl;
        return;
    }

    node* temp = ptr->previous;
    ptr->previous = temp->previous;
    temp->previous->next = ptr;

    delete temp;

    cout << "Node before " << num << " deleted!" << endl;
}

void printList() {
    if (start == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    node* temp = start;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);
    cout << endl;
}

int main() {
    create(5);

    insertbegin(10);
    insertbegin(20);
    insertend(30);
    insertafter(40, 10);
    insertbefore(50, 30);
    insertbefore(60, 30);

    cout << "Linked List: ";
    printList();

    deletebegin();
    printList();

    deleteend();
    printList();

    deleteafter(40);
    printList();

    deletebefore(40);
    printList();

    return 0;
}
