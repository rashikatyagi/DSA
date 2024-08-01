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

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    int data = 70;
    cout << "Size before insertion : " << st.size() << endl;
    cout << "Top element : " << st.top() << endl;
    insertAtBottomOfStack(st, data);
    cout << "Size after insertion : " << st.size() << endl;
    cout << "Top element : " << st.top() << endl;
    return 0;
}