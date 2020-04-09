#include <iostream>
using namespace std;

class Stack {
   private:
    int top;
    int size;
    int *arr = new int[size];

   public:
    // int GetSize(){
    //     cout<<"Enter the Size of the Stack : ";
    // }
    Stack(int s) {
        top = -1;
        size = s;
        for (int i = 0; i < s; i++) {
            arr[i] = 0;
        }
    }
    bool isEmpty() {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull() {
        if (top == (size - 1))
            return true;
        else
            return false;
    }
    void push(int val) {
        if (isFull())
            cout << "Stack Overflow" << endl;
        else {
            top++;
            arr[top] = val;
        }
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            int popvalue = arr[top];
            arr[top] = 0;
            top--;
            return popvalue;
        }
    }
    int count() {
        return (top + 1);
    }
    int peek(int pos) {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            return arr[pos];
        }
    }
    void change(int pos, int value) {
        arr[pos] = value;
        cout << "Item Changed At Location " << pos << " to " << value << endl;
    }
    void display() {
        cout << "Values in Stack are : " << endl;
        for (int i = (size - 1); i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the Size of the Stack : ";
    cin >> size;

    Stack s(size);

    s.display();

    return 0;
}