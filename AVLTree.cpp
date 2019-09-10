#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    int height;
    int count;
    node(int d) {
        this->data = d;
        this->height = 1;
        this->count = 1;
        this->left = NULL;
        this->right = NULL;
    }
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int Height(node* root) {
    if (root == NULL) {
        return -1;
    }
    return root->height;
}

node* RightRotate(node* y) {
    node* x = y->left;
    node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(Height(y->left), Height(y->right)) + 1;
    x->height = max(Height(x->left), Height(x->right)) + 1;

    return x;
}

node* LeftRotate(node* x) {
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(Height(y->left), Height(y->right)) + 1;
    x->height = max(Height(x->left), Height(x->right)) + 1;

    return y;
}


int GetBalance(node* N) {
    if (N == NULL)
        return 0;
    return Height(N->left) - Height(N->right);
}

node* insert(node*& root, int key) {
    if (root == NULL) {
        root = new node(key);
        return root;
    }

    if (key < root->data)
        insert(root->left, key);
    else if (key > root->data)
        insert(root->right, key);
    else {
        (root->count)++;
        return root;
    } 

    root->height = 1 + max(Height(root->left),Height(root->right));

    int balance = GetBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->data)
        return RightRotate(root);

    // Right Right Case
    if (balance < -1 && key > root->right->data)
        return LeftRotate(root);

    // Left Right Case
    if (balance > 1 && key > root->left->data) {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->data) {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

    /* return the (unchanged) root pointer */
    return root;
}

void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data<<"("<<root->count<<")"<< " - ";
        inorderTraversal(root->right);
        return;
    }
}

//data-left-right
void preorderTraversal(node* root) {
    if (root != NULL) {
        cout << root->data<<"("<<root->count<<")"<< " - ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return;
    }
}

int main() {
    node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    root = insert(root, 30);
    root = insert(root, 25);


    cout << "\nPreorder traversal of the AVL tree is \n";
    preorderTraversal(root);

    cout << "\n\nInorder traversal of the AVL tree is \n";
    inorderTraversal(root);

    cout<<endl;

    return 0;
}