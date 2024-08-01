#include<iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> firstNegativeIntegerOfEveryWindowOfK(vector<int> arr, int k){
    queue<int> q;
    int n = arr.size();

    // for the first window
    for(int i = 0 ; i < k ; i++){
        if(arr[i] < 0) q.push(i);
    }
    vector<int> ans;
    if(!q.empty()) ans.push_back(q.front());
    else ans.push_back(0);

    for(int i = k ; i < n ; i++){
        //check whether top index is a part of the window or not
        if(!(q.empty()) && i - q.front() >= k) q.pop();

        //check whether the new part of the window is negative or not
        if(arr[i] < 0) q.push(i);

        //storing the answer for current window
        if(!q.empty()) ans.push_back(q.front());
        else ans.push_back(0);
    }
    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(5);
    int k = 3;
    vector<int> ans = firstNegativeIntegerOfEveryWindowOfK(arr, k);
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}