#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class LLStack {
   public:
    node* top = NULL;

    bool isEmpty() {
        return top == NULL;
    }
    void push(int data) {
        node* temp = new node();
        temp->data = data;
        temp->next = top;
        top = temp;
        return;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
        } else {
            node* temp = top;
            int x = top->data;
            top = top->next;
            temp->next = NULL;
            delete (temp);
            return x;
        }
    }
    void travese() {
        node* temp;
        temp = top;
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        } else {
            while (temp != NULL) {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};

int main() {
    cout << "Stack using Linked List :\n";
    LLStack S;
    S.push(1);
    S.push(21);
    S.push(3);
    S.push(15);
    S.push(9);
    S.push(30);

    S.travese();
    cout << S.pop() << " is poped\n";
    cout << S.pop() << " is poped\n";
    S.travese();

    return 0;
}
