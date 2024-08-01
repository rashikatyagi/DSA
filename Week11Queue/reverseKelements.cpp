#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseKElements(queue<int> &q, int k){
    stack<int> st;
    int n = q.size();
    int temp = k;
    while (temp--)
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    temp = n - k;
    while(temp--){
        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "Before :" << endl;
    printQueue(q);
    int k = 3;
    reverseKElements(q, k);
    cout << "After :" << endl;
    printQueue(q);
    return 0;
}