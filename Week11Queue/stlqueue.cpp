#include<iostream>
#include <queue>
using namespace std;

int main()
{
    queue <int> q;
    
    //pushing element in queue
    q.push(10);

    //checking whether queue is empty of not
    if(q.empty()) cout << "Queue is empty" << endl;
    else cout << "Queue is not empty" << endl;

    //pushing some more elements
    q.push(20);
    q.push(30);

    // getting the front and back element
    cout << "Front element : " << q.front() << endl;
    cout << "Last element : " << q.back() << endl;

    //pop
    q.pop();

    cout << "Front element(after pop) : " << q.front() << endl;
    cout << "Last element(after pop) : " << q.back() << endl;

    return 0;
}