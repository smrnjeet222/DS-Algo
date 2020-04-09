#include <bits/stdc++.h>

using namespace std;

class node {
   public:
    char value;
    node* left;
    node* right;
    node(char d) {
        this->value = d;
        this->left = NULL;
        this->right = NULL;
    }
};

bool IsOperator(char op) {
    if (op == '*' || op == '-' || op == '+' || op == '/' || op == '^')
        return true;
    else {
        return false;
    }
}

node* ConstructTree(char pst[]) {
    stack<node*> st;
    node* temp;

    for (int i = 0; i < strlen(pst); i++) {
        if (!IsOperator(pst[i])) {
            temp = new node(pst[i]);
            st.push(temp);
        } else {
            temp = new node(pst[i]);

            node* t1 = st.top();
            st.pop();
            node* t2 = st.top();
            st.pop();

            temp->right = t1;
            temp->left = t2;

            st.push(temp);
        }
    }
    temp = st.top();
    st.pop();

    return temp;
}

void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
        return;
    }
}

void preorderTraversal(node* root) {
    if (root != NULL) {
        cout << root->value << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return;
    }
}

void postorderTraversal(node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->value << " ";
        return;
    }
}

int main() {
    char pst[] = "ab+ef*g*-";
    node* r = ConstructTree(pst);

    cout << "\n\nPostOrder Traversal : \n";
    postorderTraversal(r);

    cout << "\n\nPreOrder Traversal : \n";
    preorderTraversal(r);

    cout << "\n\nInOrder Traversal : \n\n";
    inorderTraversal(r);

    return 0;
}