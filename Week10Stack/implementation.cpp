#include<iostream>
using namespace std;

class Stack{
    private:
        int* st;
        int top;
        int size;

    public: 
        // parameterized constructor
        Stack(int size){
            st = new int[size];
            this->size = size;
            this->top = -1;
        }
        
        void insert(int data){
            // check the overflow condition
            if(top == size - 1){
                cout << "Element cannot be inserted. STACK OVERFLOW" << endl;
            }
            st[++top] = data;
        }

        void pop(){
            // check the underflow condition
            if(top == -1){
                cout << "Stack empty. STACK UNDERFLOW" << endl;
            }
            top--;
        }

        int getSize(){
            return top + 1;
        }

        bool isEmpty(){
            if(top == -1) return true;
            else return false;
        }

        int getTop(){
            if(top == -1){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return st[top];
        }
};

int main()
{
    Stack st1(10);
    cout << "Is stack empty : " << st1.isEmpty() << endl;
    cout << "Size of stack : " << st1.getSize() << endl;

    st1.insert(10);
    st1.insert(20);
    st1.insert(30);

    cout << "Is stack empty : " << st1.isEmpty() << endl;
    cout << "Size of stack : " << st1.getSize() << endl;
    cout << "Top element : " << st1.getTop() << endl;

    st1.pop();

    cout << "Size of stack : " << st1.getSize() << endl;
    cout << "Top element : " << st1.getTop() << endl;
    return 0;
}