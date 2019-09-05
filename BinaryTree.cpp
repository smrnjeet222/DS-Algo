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
    }
    node* temp = root;
    queue<node*> Q;
    Q.push(temp);

    while (!Q.empty()) {
        node* temp = Q.front();
        Q.pop();
        if (temp->left == NULL) {
            temp->left = new node(d);
            break;
        } else {
            Q.push(temp->left);
        }
        if (temp->right == NULL) {
            temp->right = new node(d);
            break;
        } else {
            Q.push(temp->right);
        }
    }
}

void DeepestNode(node*& root , node *last) {
    if (root == NULL)
        return ;
    node* current = NULL;
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        current = Q.front();
        Q.pop();
        if (current == last){
            current = NULL;
            delete last;
            return;
        }
        if (current->left != NULL){
            if (current->left == last){
                current->left = NULL;
                delete last;
                return;
            }
            else
                Q.push(current->left);
        }
        if (current->right != NULL){
            if (current->right == last){
                current->right = NULL;
                delete last;
                return;
            }
            else
                Q.push(current->right);
        } 
    }
    return ;
}

void Delete(node*& root, int key) {
    if (root == NULL)
        return;
    queue<node*> Q;
    Q.push(root);
    node* current = NULL;
    node* keyNode = NULL;
    
    while (!Q.empty()) {
        current = Q.front();
        Q.pop();
    
        if (current->data == key)
            keyNode = current;

        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
    }
    if (keyNode != NULL){
        int x = current->data;
        DeepestNode(root , current);
        keyNode->data = x;
    }
    return ;
}
//Sorted Traversal - left-data-rght
void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << "-";
        inorderTraversal(root->right);
        return;
    }
}

//data-left-right
void preorderTraversal(node* root) {
    if (root != NULL) {
        cout << root->data << "-";
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
        cout << root->data << "-";
        return;
    }
}

//IMP. spacec. O(n/2)- worst/avg. case
void levelorderTraversal(node* root) {
    if (root == NULL)
        return;
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        node* current = Q.front();
        cout << current->data << "-";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}

int main() {
    node* root = NULL;

    Insert(root, 10);
    Insert(root, 54);
    Insert(root, 30);
    Insert(root, 40);
    Insert(root, 60);
    Insert(root, 20);
    Insert(root, 90);
    Insert(root, 50);

    // cout << "\nInorder Traversal :" << endl;
    // inorderTraversal(root);
    // cout << endl;

    // cout << "\nPreorder Traversal :" << endl;
    // preorderTraversal(root);
    // cout << endl;

    // cout << "\nPostorder Traversal :" << endl;
    // postorderTraversal(root);
    // cout << endl;

    cout << "\nLevel order Traversal :" << endl;
    levelorderTraversal(root);
    cout << endl;
    cout << endl;

    Delete(root , 10);

    cout << "\nLevel order Traversal :" << endl;
    levelorderTraversal(root);
    cout << endl;
    cout << endl;



    return 0;
}