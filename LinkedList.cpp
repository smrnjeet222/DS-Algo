#include <iostream>
using namespace std;

class node{
    private:
        int data;
        node* next;
    public:
        node(){
            data ;
            next = NULL;
        }
        node(int d){
            data = d;
            next = NULL;
        }
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
                head = new node(data);
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
        void print(node*head){
    
            while(head!=NULL){
                cout<<head->data<<"->";
                head = head->next;
            }
            cout<<endl;
        }
     
};

int main(){
    node* head = NULL;
    node N;

    N.InsertAtHead(head , 5);
    N.InsertAtHead(head , 4);
    N.InsertAtHead(head , 3);
    N.InsertAtTail(head , 10);
    N.InsertAtTail(head , 12);
    N.InsertAtAnyPos(head , 6 , 2);
    N.InsertAtAnyPos(head, 0 , 0);

    cout<< endl<<N.len(head)<<endl;

    N.print(head);


    return 0;
}