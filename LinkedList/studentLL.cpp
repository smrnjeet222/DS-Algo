#include <iostream>
#include <string>
using namespace std;

class Student {
   public:
    string Name;
    int RollNo;
};

class node : public Student {
   public:
    node* next;
    node(string N, int R) {
        Name = N;
        RollNo = R;
        next = NULL;
    }
};

int len(node* head) {
    int len = 0;
    while (head != NULL) {
        head = head->next;
        len++;
    }
    return len;
}
void InsertAtHead(node*& head, string N, int R) {
    node* n = new node(N, R);
    n->next = head;
    head = n;
    return;
}
void InsertAtTail(node*& head, string N, int R) {
    if (head == NULL) {
        head = new node(N, R);
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new node(N, R);
    return;
}
void InsertAtAnyPos(node*& head, string N, int R, int pos) {
    if (head == NULL || pos == 0) {
        InsertAtHead(head, N, R);
        return;
    } else if (pos > len(head)) {
        InsertAtTail(head, N, R);
        return;
    }

    else {
        node* temp = head;
        int jump = 1;
        while (pos > jump) {
            temp = temp->next;
            jump++;
        }
        node* n = new node(N, R);
        n->next = temp->next;
        temp->next = n;
        return;
    }
}
void Delete(node*& head, int key) {
    node* temp = head;
    if (head == NULL)
        return;

    else if (head->RollNo == key) {
        node* temp = head;
        head = temp->next;
        delete temp;
        return;
    }

    while (temp->next != NULL) {
        if ((temp->next)->RollNo == key) {
            node* n = temp->next;
            temp->next = n->next;
            delete n;
            return;
        }
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Key not found" << endl;
        return;
    }
}

void Reverse(node*& head) {
    node* Currentptr = head;
    node* Prevptr = NULL;
    node* Nxt;
    while (Currentptr != NULL) {
        Nxt = Currentptr->next;
        Currentptr->next = Prevptr;
        Prevptr = Currentptr;
        Currentptr = Nxt;
    }
    head = Prevptr;
}

void print(node* head) {
    while (head != NULL) {
        cout << head->Name << ":";
        cout << head->RollNo << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node* head = NULL;

    InsertAtHead(head, "Simranjeet", 413);
    InsertAtHead(head, "Jatin", 412);
    InsertAtTail(head, "Shubh", 400);
    InsertAtAnyPos(head, "PP", 100, 2);

    cout << "Before Reversal" << endl;
    print(head);

    Delete(head, 412);
    cout << "After Deletion" << endl;
    print(head);

    Reverse(head);
    cout << "After Reversal" << endl;
    print(head);
}
