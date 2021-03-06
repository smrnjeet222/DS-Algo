#include <bits/stdc++.h>
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

void DeleteDeepestNode(node*& root, node* last) {
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

void Delete(node*& root, int key) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            root = NULL;
            return;
        }
    }

    queue<node*> Q;
    Q.push(root);

    node* current = NULL;
    node* keyNode = NULL;

    while (!Q.empty()) {
        current = Q.front();
        Q.pop();

        if (current->data == key) {
            keyNode = current;
        }

        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
    }

    if (keyNode != NULL) {
        int x = current->data;
        DeleteDeepestNode(root, current);
        keyNode->data = x;
    }
    return;
}

// max edges
int Height(node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    return max(leftHeight, rightHeight) + 1;
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

bool CheckifBST(node* root, int MinValue, int MaxValue) {
    if (root == NULL) {
        return true;
    }
    if (root->data > MinValue && root->data <= MaxValue && CheckifBST(root->left, MinValue, root->data) && CheckifBST(root->right, root->data, MaxValue)) {
        return true;
    } else {
        return false;
    }
}
// max edges
int diameter(node* root) {
    if (root == NULL) {
        return 0;
    }
    int LH = Height(root->left) + 1;
    int RH = Height(root->right) + 1;
    int Ldia = diameter(root->left);
    int Rdia = diameter(root->right);

    int d = max((LH + RH), max(Ldia, Rdia));

    return d;
}

int ConvertToSumTree(node* root) {
    if (root == NULL) {
        return 0;
    }

    int OldVal = root->data;

    root->data = ConvertToSumTree(root->left) + ConvertToSumTree(root->right);

    return OldVal + root->data;
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
void inorderStack(node* root) {
    stack<node*> S;

    while (root || !S.empty()) {
        while (root) {
            S.push(root);
            root = root->left;
        }

        root = S.top();
        S.pop();
        cout << root->data << "-";
        root = root->right;
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
void PreorderStack(node* root) {
    if (!root) {
        return;
    }
    stack<node*> S;
    S.push(root);

    while (!S.empty()) {
        node* temp = S.top();
        cout << temp->data << "-";
        S.pop();

        if (temp->right)
            S.push(temp->right);
        if (temp->left)
            S.push(temp->left);
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
void postorderIterative(node* root) {
    node* temp = root;
    unordered_set<node*> read;
    while (temp && read.find(temp) == read.end()) {
        if (temp->left && read.find(temp->left) == read.end()) {
            temp = temp->left;
        } else if (temp->right && read.find(temp->right) == read.end()) {
            temp = temp->right;
        } else {
            cout << temp->data << "-";
            read.insert(temp);
            temp = root;
        }
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

void getVerticalOrder(node* root, int hd, map<int, vector<int>>& m) {
    if (root == NULL) return;

    m[hd].push_back(root->data);

    getVerticalOrder(root->left, hd - 1, m);
    getVerticalOrder(root->right, hd + 1, m);
}
// tc : o(nlogn)
// though not good as vertical lines
// printed are not always in order
// since it uses preorder traversal
void verticalOrderTraversal(node* root) {
    map<int, vector<int>> m;
    int hd = 0;
    getVerticalOrder(root, hd, m);

    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}
// here level order is used so vertical lines are printed in order
void betterVOT(node* root) {
    if (!root) return;

    map<int, vector<int>> m;
    int hd = 0;

    queue<pair<node*, int>> Q;
    Q.push(make_pair(root, hd));
    while (!Q.empty()) {
        pair<node*, int> temp = Q.front();
        Q.pop();
        hd = temp.second;
        node* nod = temp.first;

        m[hd].push_back(nod->data);

        if (nod->left) Q.push(make_pair(nod->left, hd - 1));
        if (nod->right) Q.push(make_pair(nod->right, hd + 1));
    }

    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}

void topView(node* root) {
    if (!root) return;

    map<int, vector<int>> m;
    int hd = 0;

    queue<pair<node*, int>> Q;
    Q.push(make_pair(root, hd));
    while (!Q.empty()) {
        pair<node*, int> temp = Q.front();
        Q.pop();
        hd = temp.second;
        node* nod = temp.first;

        m[hd].push_back(nod->data);

        if (nod->left) Q.push(make_pair(nod->left, hd - 1));
        if (nod->right) Q.push(make_pair(nod->right, hd + 1));
    }

    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        cout << it->second[0] << " ";
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
    cout << "\nVertical order Traversal :" << endl;
    verticalOrderTraversal(root);
    cout << endl;
    cout << "\nBetter Vertical order Traversal :" << endl;
    betterVOT(root);
    cout << endl;
    cout << "Min-Max : " << FindMin(root) << " - " << FindMax(root) << endl;
    cout << "\nHeight of BT : " << Height(root);
    cout << "\nDiameter of BT : " << diameter(root);
    cout << "\nis BST? : " << CheckifBST(root, INT_MIN, INT_MAX) << endl;

    Delete(root, 10);
    cout << "\nLevel order Traversal After Deletion :" << endl;
    levelorderTraversal(root);
    cout << endl;
    cout << endl;

    ConvertToSumTree(root);

    cout << "\nLevel order Traversal After Sum Tree Conversion :" << endl;
    levelorderTraversal(root);
    cout << endl;
    cout << endl;

    return 0;
}