#include<iostream>
#include <queue>
using namespace std;

void interLeaveQueue(queue<int> &q){
    if(q.size() == 0 || q.size() == 1 || q.size() == 2) return;
    queue<int> sec;
    int len1 = q.size();
    int len = q.size();
    if(len & 1) len++;
    for(int i = 0 ; i < len / 2 ; i++){
        sec.push(q.front());
        q.pop();
    }
    while(!sec.empty()){
        q.push(sec.front());
        sec.pop();
        if(!(len1 & 1) || !sec.empty()){
            q.push(q.front());
            q.pop();
        }
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
    //q.push(40);
    //q.push(50);
    cout << "Before :" << endl;
    printQueue(q);
    int k = 3;
    interLeaveQueue(q);
    cout << "After :" << endl;
    printQueue(q);
    return 0;
}