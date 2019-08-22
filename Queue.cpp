#include <iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int arr[5];

    public:
        Queue(){
            front = -1;
            rear = -1;
            for (int i=0 ; i<5 ; i++){
                arr[i] = 0;
            }
        }
        bool isEmpty(){
            if (front == -1 && rear == -1)
                return true;
            else
                return false;
        }
        bool isFull(){
            if ( rear == (sizeof(arr) - 1) )
                return true;
            else 
                return false;
        }
        void enqueue(int val){
            if (isFull()){
                cout<<"Queue is Full"<<endl;
                return;
            }
            else if (isEmpty()){
                front = 0;
                rear = 0;
                arr[rear] = val;
            }
            else{ 
                rear++;
                arr[rear] = val;
            }

        }
        int dequeue(){
            int x = 0;
            if (isEmpty()){
                return 0;
            }
            else if (rear == front){
                x = arr[front];
                arr[front] = 0;
                rear = front = -1;
                return x;
            }
            else{
                x = arr[front];
                arr[front] = 0;
                front++;
                return x;
            }
        }
        int count(){
            return (rear - front + 1);
        }
        void display(){
            for (int i = 0 ; i<5  ; i++){
                cout << arr[i] << " ";
            }
        }

};

int main(){
    Queue Q;

    Q.enqueue(23);
    Q.enqueue(48);
    Q.enqueue(12);

    Q.dequeue();

    Q.display();



    return 0;
}