#include <iostream>
using namespace std;

const int A_Size = 26;

class TrieNode {
public:
    TrieNode* Children[A_Size];
    bool isEnd;
    TrieNode() {
        this->isEnd = false;
        for (int i = 0; i < A_Size; i++) {
            this->Children[i] = NULL;
        }
    }
};

void insert(TrieNode* root, string key) {
    TrieNode* temp = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!temp->Children[index]) {
            temp->Children[index] = new TrieNode();
        }
        temp = temp->Children[index];
    }
    temp->isEnd = true;
}

bool search(TrieNode* root, string key) {
    TrieNode* temp = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!temp->Children[index]) {
            return false;
        }
        temp = temp->Children[index];
    }
    return (temp && temp->isEnd);
}

int main() {
    TrieNode* root = new TrieNode();
    string s[] = {"the",
                  "this",
                  "then",
                  "here",
                  "there",
                  "bye",
                  "hello",
                  "his",
                  "hersey",
                  "their"};
    int n = sizeof(s)/sizeof(s[0]) ;

    for (int i = 0; i < n; i++) {
        insert(root , s[i]);
    }

    search(root,"there") ? cout<<"Present\n" : cout<<"Not Present\n";
    search(root,"the") ? cout<<"Present\n" : cout<<"Not Present\n";
    search(root,"them") ? cout<<"Present\n" : cout<<"Not Present\n";
    search(root,"here") ? cout<<"Present\n" : cout<<"Not Present\n";
    search(root,"her") ? cout<<"Present\n" : cout<<"Not Present\n";
    search(root,"bye") ? cout<<"Present\n" : cout<<"Not Present\n";
    search(root,"thick") ? cout<<"Present\n" : cout<<"Not Present\n";

    return 0;
}