#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        
        node(int d){
            data = d;
            next = NULL;
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
    head = n;
    return;
}


void InsertAtTail(node* &head , int d){
    if(head == NULL){
        head = new node(d);
        return ;
    }
    node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}


void InsertAtAnyPos(node*& head , int d , int pos){
    if (head == NULL || pos == 0){
        InsertAtHead(head , d);
    }
    else if(pos>len(head)){
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
        return;  
    }
}


void DeleteHead(node* &head ){
    if (head==NULL){
        return;
    }
    else{
        node * temp = head;
        head = temp->next;
        delete temp;
        return;
    }
}


void DeleteByKey(node *& head , int key){
    node *temp = head;
    if (head->data == key){
        DeleteHead(head);
        return;
    }
    while(temp->next != NULL){
        if((temp->next)->data == key){
            node *n  = temp->next;
            temp->next = n->next;
            delete n;
            return;
        }
        temp = temp->next;
    }
    if(temp->next == NULL){
        cout<<"Key not found" ; 
        return;
    }
}


void DeleteAtPos(node* &head , int pos){
    if (pos==0){
        DeleteHead(head);
        return;
    }    
    else if (pos >= len(head)){
        pos = (len(head) - 1);
    }
    
    int jump = 1;
    node* temp = head;
    
    while (jump < pos){
        temp = temp->next;
        jump++; 
    }
    node* p = temp->next;
        temp->next = p->next;
        delete p;
    
        return;     
}

    
void Reverse(node*& head){
    node * Currentptr = head;
    node * Prevptr = NULL;
    node * Nxt;
    while(Currentptr != NULL){
        
        Nxt = Currentptr->next;
        Currentptr->next = Prevptr;
        Prevptr = Currentptr;
        Currentptr  = Nxt;
    }
    head = Prevptr;
}


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


void print(node*head){
    
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}


int main(){
    node* head = NULL;

    InsertAtHead(head , 5);
    InsertAtHead(head , 4);
    InsertAtHead(head , 3);
    InsertAtTail(head , 10);
    InsertAtTail(head , 12);
    InsertAtAnyPos(head , 6 , 2);
    InsertAtAnyPos(head, 0 , 0);
    
    DeleteAtPos(head , 0);
    DeleteByKey(head , 4);

    Reverse(head);

    cout<< endl<<len(head)<<endl;

    print (head);
  
    return 0;
}