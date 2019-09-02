#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d) {
        data = d;
        next = NULL;
    }
};

int len(node* head) {
    node* n = head;
    int len = 0;
    do {
        n = n->next;
        len++;
    } while (n != head);
    return len;
}

void InsertAtHead(node*& head, int d) {
    node* n = new node(d);
    node* temp = head;
    n->next = head;
    //head = n;
    if (head == NULL) {
        n->next = n;

    } else {
        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
    }
    head = n;
    return;
}

void InsertAtTail(node*& head, int d) {
    if (head == NULL) {
        InsertAtHead(head, d);
        return;
    }
    node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    node* n = new node(d);
    tail->next = n;
    n->next = head;
    return;
}

void InsertAtAnyPos(node*& head, int d, int pos) {
    if (head == NULL || pos <= 0) {
        InsertAtHead(head, d);
    } else if (pos > len(head)) {
        InsertAtTail(head, d);
    } else {
        int jump = 1;
        node* temp = head;
        while (jump < pos) {
            temp = temp->next;
            jump++;
        }
        node* n = new node(d);
        n->next = temp->next;
        temp->next = n;
        return;
    }
}
void print(node* head) {
    node* n = head;
    if (head != NULL) {
        do {
            cout << n->data << "->";
            n = n->next;
        } while (n != head);

        cout << endl;
    }
}

int main() {
    node* head = NULL;

    InsertAtHead(head, 10);
    InsertAtHead(head, 2);
    InsertAtTail(head, 20);
    InsertAtTail(head, 30);
    InsertAtAnyPos(head, 25, 3);

    
    cout<<endl;
    print(head);

    // for (int i = 0; i < 10; i++) {
    //     cout << head->data << " ";
    //     head = head->next;
    // }
    return 0;
}
