#include<iostream>
#include <stack>
using namespace std;
void insertAtBottomOfStack(stack<int> &st, int data){
    //base case
    if(st.empty()){
        st.push(data);
        return;
    }

    //recursion
    int temp = st.top();
    st.pop();
    insertAtBottomOfStack(st, data);

    //backtracking
    st.push(temp);
}

void reverseAStack(stack<int>&st){
    //base case
    if(st.empty() || st.size() == 1) return;
    //processing
    int temp = st.top();
    st.pop();

    //recursion
    reverseAStack(st);

    //backtracking
    insertAtBottomOfStack(st, temp);
}

void printStack(stack<int>st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    cout << "Stack before reversing : ";
    printStack(st);
    reverseAStack(st);
    cout << "Stack before reversing : ";
    printStack(st);
    return 0;
}