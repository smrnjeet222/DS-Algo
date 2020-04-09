#include <iostream>
#include <string>
using namespace std;

class node {
   public:
    string name;
    int employee_id;
    node* prev;
    node* next;
    node(string name, int employee_id) {
        this->name = name;
        this->employee_id = employee_id;
        prev = NULL;
        next = NULL;
    }
};

void InsertAtHead(node*& head, string s, int id) {
    node* newnode = new node(s, id);

    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;

    head = newnode;
    return;
}

void DeleteAtEnd(node*& head) {
    node* temp = head;
    if (temp->next == NULL) {
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    node* newlast = temp->prev;
    newlast->next = NULL;
    delete temp;
    return;
}

void PrintList(node* node) {
    while (node->next != NULL) {
        cout << "Employee ID : " << node->employee_id << " , Employee Name is : " << node->name << endl;
        node = node->next;
    }
    return;
}
int main() {
    node* head = NULL;
    InsertAtHead(head, "Raman", 404);
    InsertAtHead(head, "Chetan", 420);
    InsertAtHead(head, "Deepak", 394);
    InsertAtHead(head, "Ram", 414);
    InsertAtHead(head, "Rohit", 407);
    InsertAtHead(head, "PP", 399);

    cout << "\nDoubly Linked List : " << endl;

    PrintList(head);

    DeleteAtEnd(head);
    DeleteAtEnd(head);

    cout << "\nDoubly Linked List After 2 Deletion : " << endl;
    PrintList(head);

    return 0;
}