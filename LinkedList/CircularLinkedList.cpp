#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

int len(node* head) {
    node* n = head;
    int len = 0;
    if (head == NULL)
        return 0;
    do {
        n = n->next;
        len++;
    } while (n != head);
    return len;
}

void DeleteHead(node*& head) {
    if (head == NULL) {
        return;
    } else {
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
        return;
    }
}
// one time deletion
void DeleteByKey(node*& head, int key) {
    if (head == NULL)
        return;
    node* temp = head;
    if (head->data == key) {
        DeleteHead(head);
        return;
    }
    while (temp->next != head) {
        if ((temp->next)->data == key) {
            node* n = temp->next;
            temp->next = n->next;
            delete n;
            return;
        }
        temp = temp->next;
    }
    if (temp->next == head) {
        cout << "Key not found";
        return;
    }
}
void InsertAtHead(node*& head, int d) {
    node* n = new node(d);
    node* temp = head;
    n->next = head;
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

void SortedInsert(node*& head, int d) {
    if (head == NULL) {
        InsertAtHead(head, d);
        return;
    } else if (d <= head->data) {
        InsertAtHead(head, d);
        return;
    }

    node* temp = head;
    int pos = 1;
    while (temp->next != head) {
        if (d >= temp->data && d < (temp->next)->data) {
            InsertAtAnyPos(head, d, pos);
            return;
        }
        pos++;
        temp = temp->next;
    }
    if (temp->next == head && temp->data <= d) {
        InsertAtTail(head, d);
        return;
    }
}

void SwapFirstLast(node*& head){
    node* p = head;
    while (p->next->next != head) 
       p = p->next;

    p->next->next = head->next;
    head->next = p->next;
    p->next = head;
    head = head->next;
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
    InsertAtAnyPos(head, 25, 2);
    InsertAtAnyPos(head, 25, 4);
    DeleteByKey(head, 25);

    SortedInsert(head, 1);

    SwapFirstLast(head);

    cout << endl;
    print(head);
    cout << "Length of LL : " << len(head);
    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
