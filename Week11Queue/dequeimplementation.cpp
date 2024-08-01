#include<iostream>
using namespace std;

class Deque{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    void pushBack(int element){
        //empty case
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = element;
            return;
        }
        //overflow
        if(front == 0 && rear == size - 1 || front - 1 == rear){
            cout << "Overflow" << endl;
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
    void pushFront(int element){
        //empty case
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = element;
            return;
        }
        //overflow case
        if(front == 0 && rear == size - 1 || front - 1 == rear){
            cout << "Overflow" << endl;
            return;
        }
        //circular case
        if(front == 0){
            front = size - 1;
            arr[front] = element;
            return;
        }
        //normal case
        arr[--front] = element;
    }
    void popBack(){
        //underflow case
        if(front == -1 && rear == -1){
            cout << "Underflow" << endl;
            return;
        }
        //single element case
        if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
            return;
        }
        //circular
        if(rear == 0 && front != size - 1){
            arr[rear] = -1;
            rear = size - 1;
            return;
        }
        //normal
        arr[rear--] = -1;
    }
    void popFront(){
        //underflow case
        if(front == -1 && rear == -1){
            cout << "Underflow" << endl;
            return;
        }
        //single element case
        if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
            return;
        }
        //circular case
        if(front == size - 1 && rear != 0){
            arr[front] = -1;
            front = 0;
            return;
        }
        //normal case
        arr[front++] = -1;
    }
    void printDeque(){
        for(int i = 0 ; i < size ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Deque q(5);
    q.printDeque();
    q.pushBack(34);
    q.pushBack(23);
    q.printDeque();

    q.pushFront(10);
    q.pushFront(20);
    q.printDeque();
    q.popBack();
    q.printDeque();
    q.popFront();
    q.printDeque();
    q.pushFront(48);
    q.pushFront(435);
    q.printDeque();
    q.pushBack(34);
    q.printDeque();
    q.pushFront(45);
    return 0;
}