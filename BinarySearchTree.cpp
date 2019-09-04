#include <iostream>
#include <queue>
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

int FindMin(node* root) {
    node* temp = root;
    if (root == NULL) {
        return -1;
    } else if (root->left == NULL) {
        return root->data;
    }
    return (FindMin(root->left));
}

int FindMax(node* root) {
    node* temp = root;
    if (root == NULL) {
        return -1;
    } else if (root->right == NULL) {
        return root->data;
    }
    return (FindMax(root->right));
}

int FindHeight(node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}
void Delete(node*& root) {
}

node* Search(node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    else if (key < root->data)
        return Search(root->left, key);
    else
        return Search(root->right, key);
}

//Sorted Traversal
void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << "-";
        inorderTraversal(root->right);
        return;
    }
}

void preorderTraversal(node* root) {
    if (root != NULL) {
        cout << root->data << "-";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return;
    }
}

void postorderTraversal(node* root) {
    if (root != NULL) {
        cout << root->data << "-";
        postorderTraversal(root->right);
        postorderTraversal(root->left);
        return;
    }
}

void levelorderTraversal(node* root) {
    if (root == NULL)
        return;
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        node* current = Q.front();
        cout << current->data<< "-";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop();
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
    Insert(root, 60);
    Insert(root, 15);
    Insert(root, 22);
    Insert(root, 11);
    Insert(root, 33);

    Search(root, 10) ? cout << "Key Found " : cout << "Key Missing ";

    cout << "\nInorder Traversal :" << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "\nPreorder Traversal :" << endl;
    preorderTraversal(root);
    cout << endl;

    cout << "\nPostorder Traversal :" << endl;
    postorderTraversal(root);
    cout << endl;

    cout << "\nLevel order Traversal :" << endl;
    levelorderTraversal(root);
    cout << endl;
    cout << endl;

    cout << "Min to Max : " << FindMin(root) << " to " << FindMax(root) << endl;
    cout << "Height : " << FindHeight(root) << endl;

    return 0;
}