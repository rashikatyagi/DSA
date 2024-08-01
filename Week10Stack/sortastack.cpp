#include<iostream>
#include<stack>
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

void SortAStack(stack<int> &st){
    //base case
    if(st.empty() || st.size() == 1) return;

    //processing
    int temp = st.top();
    st.pop();

    //recursion
    SortAStack(st);

    //backtracking
    insertInASortedStack(st, temp);
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
    st.push(9);
    st.push(30);
    st.push(40);
    st.push(5);
    st.push(6);

    cout << "Before : ";
    printStack(st);
    SortAStack(st);
    cout << "After : ";
    printStack(st);
    return 0;
}