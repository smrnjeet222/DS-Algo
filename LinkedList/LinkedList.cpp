#include <assert.h>
#include <bits/stdc++.h>
using namespace std;

typedef uintptr_t ut;

class node {
   public:
    int data;
    node* next;

    node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

int len(node* head) {
    int len = 0;
    while (head != NULL) {
        head = head->next;
        len++;
    }
    return len;
}

int lenRecursive(node*& head) {
    if (head == NULL) {
        return 0;
    }

    return 1 + lenRecursive(head->next);
}

void InsertAtHead(node*& head, int d) {
    node* n = new node(d);
    n->next = head;
    head = n;
    return;
}

void InsertAtTail(node*& head, int d) {
    if (head == NULL) {
        head = new node(d);
        return;
    }
    node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}

void InsertAtAnyPos(node*& head, int d, int pos) {
    if (head == NULL || pos <= 0) {
        InsertAtHead(head, d);
    } else if (pos > len(head)) {
        InsertAtTail(head, d);
    } else {
        int jump = 1;
        node* temp = head;
        while (jump < pos) {
            temp = temp->next;
            jump++;
        }
        node* n = new node(d);
        n->next = temp->next;
        temp->next = n;
        return;
    }
}

void DeleteHead(node*& head) {
    if (head == NULL) {
        return;
    } else {
        node* temp = head;
        head = temp->next;
        delete temp;
        return;
    }
}

void DeleteByKey(node*& head, int key) {
    node* temp = head;
    if (head->data == key) {
        DeleteHead(head);
        return;
    }
    while (temp->next != NULL) {
        if ((temp->next)->data == key) {
            node* n = temp->next;
            temp->next = n->next;
            delete n;
            return;
        }
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Key not found";
        return;
    }
}

void DeleteAtPos(node*& head, int pos) {
    if (pos <= 0) {
        DeleteHead(head);
        return;
    } else if (pos >= len(head)) {
        pos = (len(head) - 1);
    }

    int jump = 1;
    node* temp = head;

    while (jump < pos) {
        temp = temp->next;
        jump++;
    }
    node* p = temp->next;
    temp->next = p->next;
    delete p;

    return;
}

node* ReverseRecursively(node*& head) {
    if (head == NULL || head->next == NULL)
        return head;

    node* rest = ReverseRecursively(head->next);
    /*node* p = head->next;
    p->next = head;*/
    //OR
    head->next->next = head;
    head->next = NULL;

    return rest;
}

void Reverse(node*& head) {
    node* Currentptr = head;
    node* Prevptr = NULL;
    node* Nxt;
    while (Currentptr != NULL) {
        Nxt = Currentptr->next;
        Currentptr->next = Prevptr;
        Prevptr = Currentptr;
        Currentptr = Nxt;
    }
    head = Prevptr;
}

void ReverseUsing2Ptr(node*& head) {
    node* prev = NULL;
    node* current = head;

    while (current != NULL) {
        current = (node*)((ut)prev ^ (ut)current ^ (ut)(current->next) ^ (ut)(current->next = prev) ^ (ut)(prev = current));
    }
    head = prev;
}

void SwapByKey(node*& head, int x, int y) {
    if (x == y)
        return;
    node* currx = head;
    ;
    node* px = NULL;
    while (currx && currx->data != x) {
        px = currx;
        currx = currx->next;
    }
    node* curry = head;
    ;
    node* py = NULL;
    while (curry && curry->data != y) {
        py = curry;
        curry = curry->next;
    }

    if (currx == NULL || curry == NULL)
        return;

    if (px != NULL)
        px->next = curry;
    else
        head = curry;

    if (py != NULL)
        py->next = currx;
    else
        head = currx;

    node* temp = curry->next;
    curry->next = currx->next;
    currx->next = temp;
}

void pairWiseSwapData(node*& head) {
    if (head != NULL && head->next != NULL) {
        swap(head->data, head->next->data);

        pairWiseSwapData(head->next->next);
    }
}

bool SearchRecursively(node* head, int key) {
    if (head == NULL)
        return false;

    if (head->data == key) {
        return true;
    } else {
        return SearchRecursively(head->next, key);
    }
}

//Nth Node from the end
node* NthLastPosition(node*& head, int pos) {
    if (head == NULL || head->next == NULL) {
        return head;
    } else if (pos <= 0) {
        pos = 1;
    } else if (pos > len(head)) {
        pos = len(head);
    }

    node* slow = head;
    node* fast = head;

    while (pos--) {
        fast = fast->next;
    }
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// Runner Technique (to return 2nd  mid for even len : node*fast = head)
node* midPoint(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void MergeSort(node* s) {
}

node* FloydsAlgorithm(node*& head) {
    node* slow = head;
    node* fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return slow;
    }
    return NULL;
}

int count(node* n) {
    node* temp = n;
    int length = 1;
    while (temp->next != n) {
        length++;
        temp = temp->next;
    }
    return length;
}

int LoopLength(node*& head) {
    node* slow = head;
    node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return count(slow);
    }
    return 0;
}

node* StartOfLoop(node*& head) {
    node* q = head;
    node* p = FloydsAlgorithm(head);
    if (!p) {
        return NULL;
    }
    while (q != p) {
        q = q->next;
        p = p->next;
    }
    return p;
}

void BreakLoop(node*& head) {
    node* p = StartOfLoop(head);
    if (!p) {
        return;
    }
    int l = (LoopLength(head) - 1);
    while (l--) {
        p = p->next;
    }
    p->next = NULL;
    cout << "Loop Breaked" << endl;
}

void print(node* head) {
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node* head = NULL;

    InsertAtHead(head, 5);
    InsertAtHead(head, 4);
    InsertAtHead(head, 3);
    InsertAtTail(head, 10);
    InsertAtTail(head, 12);
    InsertAtTail(head, 100);

    head->next->next->next->next->next->next = head->next->next;

    FloydsAlgorithm(head) ? cout << "Loop Present" : cout << "No Loop";
    cout << endl;

    cout << LoopLength(head) << endl;
    cout << "Start Of Loop : " << StartOfLoop(head) << endl;

    BreakLoop(head);
    InsertAtAnyPos(head, 6, 2);
    InsertAtAnyPos(head, 0, 0);

    DeleteAtPos(head, 0);
    DeleteByKey(head, 6);

    head = ReverseRecursively(head);
    ReverseUsing2Ptr(head);

    pairWiseSwapData(head);

    SwapByKey(head, 4, 100);

    cout << "Mid Point : " << midPoint(head)->data << endl;

    cout << "Length is : " << len(head) << " and " << lenRecursive(head) << endl;

    cout << "Nth Position from Last : " << NthLastPosition(head, -3)->data << endl;

    SearchRecursively(head, 11) ? cout << "Key is present" : cout << "Key is absent";
    cout << endl;

    print(head);

    return 0;
}