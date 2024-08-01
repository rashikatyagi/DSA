#include<iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n, 0);
    stack <int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0 ; i--)
    {
        while(!st.empty() && st.top() > arr[i]) st.pop();
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n, 0);
    stack <int> st;
    st.push(-1);
    for (int i = 0; i < n ; i++)
    {
        while(!st.empty() && st.top() > arr[i]) st.pop();
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);
    vector<int> ans = nextSmallerElement(arr);

    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    vector<int> ans1 = prevSmallerElement(arr);

    for(int i = 0 ; i < ans1.size() ; i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;
    return 0;
}