#include<iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "rashika";
    stack<char> st;

    //insert the elements of the string into the stack
    for(int i = 0 ; i < str.length() ; i++){
        char ch = str[i];
        st.push(ch);
    }
    while( !st.empty() ){
        cout << st.top();
        st.pop();
    }
    cout << endl;
    return 0;
}