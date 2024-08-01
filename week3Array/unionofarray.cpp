#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;

// using map
vector<int> UnionOfTwoArraysMAP(int* arr1, int* arr2, int n, int m){
    map<int, int> mp;
    for(int i = 0 ; i < n ; i++){
        mp[arr1[i]]++;
    }
    for(int i = 0 ; i < m ; i++){
        mp[arr2[i]]++;
    }
    vector<int> arr;
    for(auto i : mp){
        arr.push_back(i.first);
    }
    return arr;
}

// using set
vector<int> UnionOfTwoArraysSET(int* arr1, int* arr2, int n, int m){
    set<int> st;
    for(int i = 0 ; i < n ; i++){
        st.insert(arr1[i]);
    }
    for(int i = 0 ; i < m ; i++){
        st.insert(arr2[i]);
    }
    vector<int> ans;
    for(auto i : st){
        ans.push_back(i);
    }
    return ans;
}

// vector <int> UnionOfTwoArraysPOINTERS(int* arr1, int* arr2, int n, int m){
//     int i = 0, j = 0;
//     vector<int> ans;
//     while(i < n && j < m){
//         if(arr1[i] == arr2[j]){
//             if(ans.size() == 0 || ans.back() != arr1[i]){
//                 ans.push_back(arr1[i++]);
//             }
//         }
//         else if(arr1[i] < arr2[j]) ans.push_back(arr1[i++]);
//         else ans.push_back(arr2[j++]);
//     }
//     while(i < n){
//         if(ans.back() != arr1[i]){
//             ans.push_back(arr1[i++]);
//         }
//     }
//     while(j < m){
//         if(ans.back() != arr2[j]){
//             ans.push_back(arr2[j++]);
//         }
//     }
//     return ans;
// }

int main()
{
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[] = {2,3,4,4,5,11,12};
    int n = 10, m = 7;
    // vector<int> ans = UnionOfTwoArraysMAP(arr1, arr2, n, m) ;
    // vector<int> ans = UnionOfTwoArraysSET(arr1, arr2, n, m) ;
    vector<int> ans = UnionOfTwoArraysPOINTERS(arr1, arr2, n, m);
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}