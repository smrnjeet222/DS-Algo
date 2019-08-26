#include <bits/stdc++.h>
#include <assert.h> 
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

int lenRecursive(node* &head){
    if(head==NULL){
        return 0 ;
    }

    return 1+lenRecursive(head->next);
    
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

node* ReverseRecursively(node*& head){
    if (head == NULL || head->next == NULL)  
        return head; 
    
    node* rest = ReverseRecursively(head->next);
    /*node* p = head->next;
    p->next = head;*/
    //OR 
    head->next->next = head;
    head->next=NULL;

    return rest;  
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

void swap(node*& head  , int x , int y ){
    if(x==y)
        return;
    node* tempx = head;;
    node* px = NULL;
    while(tempx && tempx->data != x){
        px =  tempx;
        tempx = tempx->next;
    }
    node* tempy = head;;
    node* py = NULL;
    while(tempy && tempy->data != y){
        py =  tempy;
        tempy = tempy->next;
    }
    if (tempx == NULL || tempy == NULL)  
        return;
    if(px!=NULL)
        px->next = tempy;
    else
        head = tempy;

    if(py!=NULL)
        py->next = tempx;
    else
        head = tempx; 

    node *temp = tempy->next;  
    tempy->next = tempx->next;  
    tempx->next = temp;
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

//Nth Node from the end
node* NthLastPosition(node* &head , int pos){
    if(head==NULL||head->next==NULL){
        return head;
    }
    if(pos == 0 || pos>len(head)){
        assert(0);
    }
    node* slow = head;
    node* fast = head;

    while(pos--){
        fast = fast->next;
    }
    while(fast!= NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
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

void MergeSort(node* s){
   

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
    InsertAtTail(head , 100);
    InsertAtAnyPos(head , 6 , 2);
    InsertAtAnyPos(head, 0 , 0);
    
    //DeleteAtPos(head , 0);
    DeleteByKey(head , 4);

    //Reverse(head);

    cout<<"Mid Point : " <<midPoint(head)->data << endl;

    cout<<"Length is : "<<len(head)<<" and "<<lenRecursive(head)<<endl;

    cout<<"Nth Position from Last : "<<NthLastPosition(head , 1)->data<<endl;

    SearchRecursively(head , 11) ? cout<<"Key is present" : cout << "Key is absent";
    cout<<endl;

    head = ReverseRecursively(head);

    swap(head , 0 ,100);

    print (head);
  
    return 0;
}