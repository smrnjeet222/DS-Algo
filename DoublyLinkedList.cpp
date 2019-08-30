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


void print(node*head){
    
    while(head!=NULL){
        cout<<head->data<<"->";
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

    print(head);

    return 0;
}