#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void Insert(node*& root, int d) {
    if (root == NULL) {
        root = new node(d);
        return;
    } else if (d >= root->data)
        Insert(root->right, d);
    else
        Insert(root->left, d);

    return;
}

node* Search(node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    else if (key < root->data)
        return Search(root->left, key);
    else
        return Search(root->right, key);
}

void print(node* root) {
    if (root != NULL) {
        print(root->left);
        cout << root->data << "-";
        print(root->right);
        return;
    }
}

int main() {
    node* root = NULL;
    Insert(root, 20);
    Insert(root, 10);
    Insert(root, 50);
    Insert(root, 5);
    Insert(root, 12);
    Insert(root, 25);
    Insert(root, 33);

    Search(root, 10) ? cout << "Key Found " : cout << "Key Missing ";

    cout << endl;
    print(root);
    cout << endl;

    return 0;
}