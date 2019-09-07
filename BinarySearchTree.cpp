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

node* FindMin(node* root) {
    node* temp = root;
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    }
    return (FindMin(root->left));
}

node* FindMax(node* root) {
    node* temp = root;
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
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

//IMP.
node* Delete(node*& root, int d) {
    if (root == NULL)
        return root;
    else if (d < root->data)
        root->left = Delete(root->left, d);
    else if (d > root->data)
        root->right = Delete(root->right, d);
    //when data is found
    else {
        //Case 1 : no child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        //case 2 : 1 child
        else if (root->left == NULL) {
            node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            node* temp = root;
            root = root->left;
            delete temp;
        }
        //case 3: 2 children
        else {
            node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

node* Search(node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    else if (key < root->data)
        return Search(root->left, key);
    else
        return Search(root->right, key);
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

void AllInfo(node* root) {
    Search(root, 11) ? cout << "Key Found " : cout << "Key Missing ";

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

    cout << "Min to Max : " << FindMin(root)->data << " to " << FindMax(root)->data << endl;
    cout << "Height : " << FindHeight(root) << endl;
    cout<<"\nis BST? : "<<CheckifBST(root , INT_MIN , INT_MAX)<<endl;

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


    AllInfo(root);



    Delete(root, 20);


    cout << "\nAfter Deletion : " << endl;

    AllInfo(root);


    return 0;
}