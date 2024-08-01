#include<iostream>
using namespace std;

class Stack{
    int* arr;
    int size;
    int top1;
    int top2;

    public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int data){
        top1++;
        if(top1 < top2){
            arr[top1] = data; 
        }
        else{
            cout << "Stack overflow" << endl;
        }
    }
    void push2(int data){
        top2--;
        if(top2 > top1){
            arr[top2] = data;
        }
        else{
            cout << "Stack overflow" << endl;
        }
    }
    void pop1(){
        if(top1 == -1){
            cout << "Stack Underflow" << endl;
            return;
        }
        arr[top1] = 0;
        top1--;
    }
    void pop2(){
        if(top2 == size){
            cout << "Stack underflow" << endl;
            return;
        }
        arr[top2] = 0;
        top2++;
    }
    void print(){
        cout << "Top1 : " << top1 << endl;
        cout << "Top2 : " << top2 << endl; 
        for(int i = 0 ; i < size ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(6);
    st.print();
    st.push1(34);
    st.print();
    st.push2(35);
    st.push2(43);
    st.print();
    st.pop1();
    st.print();
    st.pop1();
    st.print();
    return 0;
}