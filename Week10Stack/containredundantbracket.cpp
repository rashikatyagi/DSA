#include<iostream>
#include <stack>
using namespace std;

bool checkRedundantBracket(string &s){
    stack<char> st;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*'){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            int operatorCount = 0;
            while(!st.empty() && st.top() != '('){
                char ch = st.top();
                if(ch == '+' || ch == '-' || ch == '/' || ch == '*') operatorCount++;
                st.pop();
            }
            st.pop();

            if(operatorCount == 0) return true;
        }
    }
    return false;
}

int main()
{
    string s = "(a+(b))";
    cout << "Contain redandant bracket : " << checkRedundantBracket(s) << endl;
    return 0;
}