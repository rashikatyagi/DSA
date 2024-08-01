#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> q;
    q.push_back(10);
    cout << q.size() << endl;

    q.push_front(20);
    
    cout << "Front : " << q.front() << endl;
    cout << "Back : " << q.back() << endl;
    cout << q.size() << endl;
    q.push_front(10);
    q.push_front(30);
    q.push_front(240);
    q.push_front(200);q.push_front(320);

    cout << "Front : " << q.front() << endl;
    cout << "Back : " << q.back() << endl;
    cout << q.size() << endl;

    q.pop_front();
    cout << "Front : " << q.front() << endl;
    cout << "Back : " << q.back() << endl;
    cout << q.size() << endl;

    q.pop_front();
    q.pop_back();
    cout << "Front : " << q.front() << endl;
    cout << "Back : " << q.back() << endl;
    cout << q.size() << endl;
    return 0;
}