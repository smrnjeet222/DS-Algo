#include <iostream>
#include <queue>

using namespace std;

class info {
public:
    string type;
    string name;
    int yr;
};

class node : public info{
public:
    node* left;
    node* right;

    node(string t, string n , int yr ) {
        this->type = t;
        this->name = n;
        this->yr = yr;
        this->left = NULL;
        this->right = NULL;
    }
};

void Insert(node*& root, string t, string n, int yr) {
    if (root == NULL) {
        root = new node(t ,n, yr);
        return;
    }
    node* temp = root;
    queue<node*> Q;
    Q.push(temp);

    while (!Q.empty()) {
        node* temp = Q.front();
        Q.pop();
        if (temp->left == NULL) {
            temp->left = new node(t ,n, yr);
            break;
        } else {
            Q.push(temp->left);
        }
        if (temp->right == NULL) {
            temp->right = new node(t ,n, yr);
            break;
        } else {
            Q.push(temp->right);
        }
    }
}

void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << "("<<root->name<<","<<root->type<<","<<root->yr<< ")" << " - ";
        inorderTraversal(root->right);
        return;
    }
}

//data-left-right
void preorderTraversal(node* root) {
    if (root != NULL) {
        cout << "("<<root->name<<","<<root->type<<","<<root->yr<< ")" << " - ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return;
    }
}

//left-right-data
void postorderTraversal(node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << "("<<root->name<<","<<root->type<<","<<root->yr<< ")" << " - ";
        return;
    }
}

int main() {
    node* root = NULL;

    Insert(root, "Car", "Audi", 2004);
    Insert(root, "Truck", "Mahindra", 2011);
    Insert(root, "Car", "Maruti", 2006);
    Insert(root, "Bike", "Honda", 2015);
    Insert(root, "Car", "Toyota", 2009);
    Insert(root, "Car", "BMW", 2015);
    Insert(root, "Truck", "Ford", 2014);

    cout << "\nInorder Traversal :" << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "\nPostorder Traversal :" << endl;
    postorderTraversal(root);
    cout << endl;

    cout << "\nPreorder Traversal :" << endl;
    preorderTraversal(root);
    cout << endl;

    return 0;
}