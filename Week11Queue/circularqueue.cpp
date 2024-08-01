#include<iostream>
using namespace std;

class CQueue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    CQueue(int size){
        arr = new int[size];
        this->size = size;
        this->front = -1;
        this->rear = -1;
    }

    void push(int element){
        //empty queue
        if(front == -1 && rear == -1){
            front++; rear++;
            arr[rear] = element;
            return;
        }
        //overflow case
        if(rear == size - 1 && front == 0 || rear == front - 1){
            cout << "Queue overflow" << endl;
            return;
        }
        //circular case
        if(rear == size - 1){
            rear = 0;
            arr[rear] = element;
            return;
        }
        //normal case
        arr[++rear] = element;
    }

    void pop(){
        //empty queue
        if(front == -1 && rear == -1){
            cout << "Queue underflow" << endl;
            return;
        }
        //single element
        if(front == rear){
            arr[front] = -1;
            front = -1; 
            rear = -1; // queue is now again empty
            return;
        }
        //circular case
        if(front == size - 1){
            arr[front] = -1;
            front = 0;
            return;
        }
        //normal case
        arr[front++] = -1;
    }

    void printCQueue(){
        for(int i = 0 ; i < size ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CQueue q(5);
    q.printCQueue();
    q.push(10);
    q.push(20);
    q.push(30);
    q.printCQueue();

    q.pop();
    q.printCQueue();

    q.push(49);
    q.push(56);
    q.printCQueue();

    q.push(23);
    q.printCQueue();
    q.push(34);

    q.pop();
    q.printCQueue();
    return 0;
}