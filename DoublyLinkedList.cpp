#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;
        
    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

int len(node* head){
    int len = 0;
    while(head != NULL){
        head = head->next;
        len++;
    }
    return len;
}

void InsertAtHead(node*& head , int d){
    node* n = new node(d);
    n->next = head;

    if(head!= NULL)
        head->prev = n;

    head = n;
    return;
}


void InsertAtTail(node*& head , int d){
    if (head == NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    return;
}


void InsertAt(node*& head , int d, int pos){
    if(head == NULL || pos == 0){
        InsertAtHead(head , d);
    }
    else if(pos >= len(head)){
        InsertAtTail(head , d);
    }
    else{
        int jump = 1;
        node* temp = head;
        while (jump < pos){
           temp = temp->next;
           jump++; 
        }
        node* n = new node(d);
        n->next = temp->next;
        temp->next = n;

        n->next->prev = n;
        n->prev = temp; 
        return;  
    }

}

void Delete(node* &head , int pos){
    node* temp = head;
    if(head == NULL){
        cout<<"No elements in Linked List"<<endl;
        return;
    }
    else if(head->next == NULL){
        head = NULL;
        cout<<"No elements in Linked List"<<endl;
        return;
    }
    else if(pos==0){
        head = temp->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    else if((pos+1)>=len(head)){
        while(temp->next->next != NULL){
           temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        return;
    }
    else{
        int jump = 1;
        while (jump < pos){
            temp = temp->next;
            jump++; 
        }
        node*n = temp->next;
        temp->next = n->next;
        temp->next->prev = n->prev;
        delete n;
        return;
    }
}

// Runner Technique (to return 2nd  mid for even len : node*fast = head)
node* midPoint(node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    node*slow = head;
    node*fast = head->next;
    
    while(fast!=NULL &&  fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;    
}

bool SearchRecursively(node* head , int key){
    if (head == NULL)
        return false;

    if(head->data==key){
        return true;
    }
    else{
        return SearchRecursively(head->next , key);
    }
    
}

// void Reverse(node*& head){

//     node* temp = NULL;
//     node* curr = head;

//     while(curr!= NULL){
//         temp = curr->prev;
//         curr->prev = curr->next;
//         curr->next = temp;
//         curr = curr->prev;
//     }
//     cout<<curr->data<<endl;
//         if (temp!= NULL)
//         head = curr;

//     return;
// }


void print(node*head){
    
    while(head!=NULL){
        cout<<head->data<<" - ";
        head = head->next;
    }
    cout<<endl;
}


int main(){
    node* head = NULL;
    InsertAtTail(head , 40);
    InsertAtHead(head , 10);
    InsertAtHead(head , 5);
    InsertAtTail(head , 50);
    InsertAtTail(head , 60);
    InsertAtTail(head , 70);
    InsertAt(head , 20 ,2);

    Delete(head , 0);

    SearchRecursively(head , 50) ? cout<<"true": cout<<"false";
    cout<<endl;
    //Reverse(head);

    print(head);

    return 0;
}