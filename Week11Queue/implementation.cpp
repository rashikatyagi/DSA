/*
Implement the following STL functions:-
1. create
2. push
3. pop
4. size
5. empty
6. front
7. back
*/
#include<iostream>
#include <vector>
using namespace std;

class Queue{
    public:
    int* arr;
    int size;
    int front;
    int back;


    Queue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        back = -1;
    }

    void push(int val){
        //if queue is full
        if(back == size - 1){
            cout << "Queue overflow" << endl;
            return;
        }
        //empty queue case
        if(front == -1 && back == -1){
            front++; back++;
        }
        else{
            back++;
        }
        arr[back] = val;
    }

    void pop(){
        //Queue empty case
        if(front == -1 && back == -1){
            cout << "Stack underflow" << endl;
            return;
        }
        //single element case
        if(front == back){
            arr[front] = -1;
            front = back = -1; // queue is empty again
        }
        else{
            arr[front++] = -1;
        }
    }

    int getSize(){
        if(front == -1 && back == -1) return 0;
        else return back - front + 1;
    }

    bool isEmpty(){
        if(front == -1 && back == -1) return true;
        else return false;
    }

    int getFront(){
        if(front == -1 && back == -1){
            cout << "Queue is empty, no front element" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int getBack(){
        if(front == -1 && back == -1){
            cout << "Queue is empty, no back element" << endl;
            return -1;
        }
        else{
            return arr[back];
        }
    }

    void printQueue(){
        for(int i = 0 ; i < size ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);
    q.printQueue();
    
    q.push(10);
    q.push(20);
    q.printQueue();
    cout << "Size of queue : " << q.getSize() << endl;

    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.printQueue();

    q.pop();
    q.printQueue();

    q.pop();
    q.printQueue();

    cout << "Get front element : " << q.getFront() << endl;
    cout << "Get back element : " << q.getBack() << endl;
    return 0;
}