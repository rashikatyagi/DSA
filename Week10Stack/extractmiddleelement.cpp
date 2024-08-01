#include<iostream>
#include <stack>
using namespace std;

int extractMiddleElement(stack<int> &st, int pos){
    //base case
    if(pos == 1){
        int temp = st.top();
        st.pop();
        return temp;
    }

    //processing
    int temp = st.top();
    st.pop();
    int ans = extractMiddleElement(st, --pos);

    //backtracking
    st.push(temp);
    return ans;
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // st.push(60);

    int pos;
    int stackSize = st.size();
    if(stackSize % 2 == 0){
        pos = (stackSize / 2);
    }
    else pos = (stackSize / 2) + 1;

    cout << "Stack size before extraction : " << stackSize << endl;
    int middle_element = extractMiddleElement(st, pos);
    cout << "Middle element is : " << middle_element << endl; 
    cout << "Stack size after extraction : " << st.size() << endl;
    return 0;
}