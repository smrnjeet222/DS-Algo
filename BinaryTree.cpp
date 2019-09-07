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

void DeleteDeepestNode(node* root, node* last) {
    if (root == NULL)
        return;
    node* current = NULL;
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        current = Q.front();
        Q.pop();
        if (current == last) {
            current = NULL;
            delete last;
            return;
        }
        if (current->left != NULL) {
            if (current->left == last) {
                current->left = NULL;
                delete last;
                return;
            } else
                Q.push(current->left);
        }
        if (current->right != NULL) {
            if (current->right == last) {
                current->right = NULL;
                delete last;
                return;
            } else
                Q.push(current->right);
        }
    }
    return;
}

void Delete(node* root, int key) {
    if (root == NULL)
        return;

    queue<node*> Q;
    Q.push(root);
    node* current = NULL;
    node* keyNode = NULL;

    while (!Q.empty()) {
        current = Q.front();
        Q.pop();

        if (current->data == key) {
            keyNode = current;
            break;
            //remove break if want to delete last occurence
        }

        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
    }
    if (keyNode != NULL) {
        int x = current->data;
        DeleteDeepestNode(root, current);
        if (keyNode != current)
            keyNode->data = x;
    }
    return;
}

int FindMin(node* root) {
    // Base case
    if (root == NULL)
        return INT_MAX;

    int res = root->data;
    int lres = FindMin(root->left);
    int rres = FindMin(root->right);
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}

int FindMax(node* root) {
    // Base case
    if (root == NULL)
        return INT_MIN;

    int res = root->data;
    int lres = FindMax(root->left);
    int rres = FindMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
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

bool CheckifBST(node* root , int MinValue , int MaxValue) {
    if (root == NULL ) {
        return true;
    }
    if ( root->data > MinValue && root->data <= MaxValue && CheckifBST(root->left ,MinValue , root->data ) && CheckifBST(root->right ,root->data, MaxValue )) {
        return true;
    } else {
        return false;
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
    Insert(root, 5);
    Insert(root, 30);
    Insert(root, 4);
    Insert(root, 7);
    Insert(root, 25);
    Insert(root, 60);
    Insert(root, 26);

    cout << "\nInorder Traversal :" << endl;
    inorderTraversal(root);
    cout << endl;

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
    cout << "Min-Max : " << FindMin(root) << " - " << FindMax(root) << endl;

    cout << "\nis BST? : " << CheckifBST(root, INT_MIN , INT_MAX) << endl;

    Delete(root, 60);

    cout << "\nLevel order Traversal After Deletion :" << endl;
    levelorderTraversal(root);
    cout << endl;
    cout << endl;

    return 0;
}