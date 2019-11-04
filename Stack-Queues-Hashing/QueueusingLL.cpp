#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class LLQueue {
public:
    node* front = NULL;
    node* rear = NULL;

    bool isEmpty() {
        return rear == NULL;
    }

    void push(int data) {
        node* temp = new node();
        if (isEmpty()) {
            front = temp;
        }
        temp->data = data;
        temp->next = rear;
        rear = temp;
        return;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return 0;
        } else {
            node* temp = front;
            node* t = rear;
            int x = front->data;
            if(front == rear){
                delete(temp);
                front = NULL;
                rear = NULL;
                return x;
            }
            while (t->next->next) {
                t = t->next;
            }
            front = t;
            front->next = NULL;
            delete (temp);
            return x;
        }
    }
    void travese() {
        node* temp = rear;
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        } else {
            while (temp != NULL) {
                cout << temp->data << "-";
                temp = temp->next;
            }
            return;
        }
    }
};

int main() {
    cout << "Queue using Linked List :\n";
    LLQueue Q;
    Q.push(1);
    Q.push(21);
    Q.push(3);
    Q.push(15);
    Q.push(9);
    Q.push(30);
    Q.push(19);
    Q.push(11);


    Q.travese();

    cout << "\n\n";
    cout << Q.pop() << " is poped\n";
    cout << Q.pop() << " is poped\n";
    cout << "\n";

    cout << "Queue using Linked List after poping :\n";
    Q.travese();
    cout << "\n";

    return 0;
}
