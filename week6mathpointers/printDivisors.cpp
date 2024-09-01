#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// brute force approach
void printDivisors1(int n){
    for(int i = 1 ; i <= n ; i++){
        if(n % i == 0){
            cout << i << " ";
        }
    }
    cout << endl;
}

// better approach
void printDivisors2(int n){
    vector<int> ans;
    for(int i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            ans.push_back(i);
            if((n / i) != i) ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int n = 36;
    printDivisors1(n);
    printDivisors2(n);
    return 0;
}