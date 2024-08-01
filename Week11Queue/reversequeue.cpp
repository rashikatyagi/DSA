#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q){
    //base case
    if(q.empty()){
        return;
    }

    int element = q.front();
    q.pop();
    
    reverseQueue(q);

    q.push(element);
}

void reverseQueueUsingStack(queue<int> &q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "Before :" << endl;
    cout << "Front : " << q.front() << " Back : " << q.back() << endl;
    reverseQueueUsingStack(q);
    // reverseQueue(q);
    cout << "After :" << endl;
    cout << "Front : " << q.front() << " Back : " << q.back() << endl;
    return 0;
}