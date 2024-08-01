#include<iostream>
#include <stack>
using namespace std;

void insertInASortedStack(stack<int> &st, int data){
    //base case
    if(st.empty() || st.top() < data){    
        // IF ELEMENT IS LESS THAN THE SMALLEST ELEMENT, .EMPTY() CONDITION IS IMPORTANT
        st.push(data);
        return;
    }

    //processing
    int temp = st.top();
    st.pop();
    
    //recursion
    insertInASortedStack(st, data);

    //backtracking
    st.push(temp);
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

    int data = 9;
    cout << "Before inserting : ";
    printStack(st);
    insertInASortedStack(st, data);
    cout << "After inserting : ";
    printStack(st);
    return 0;
}