#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printvv(vector<vector<int> > &arr){
    for(int i = 0 ; i < arr.size() ; i++){
        for(int j = 0 ; j < arr[i].size() ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printVec(vector<int> &arr){
    for(int i = 0 ; i < arr.size() ; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool myComp(int &a, int &b){
    return a > b;
}

bool myComp1(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

bool myComp2()

int main()
{
    vector<int> arr = {1, 5, 3, 7, 8, 2};
    vector<vector<int>> arr1 = {
      {2, 3, 4},
      {6, 7, 8},
      {4, 9, 6},
      {1, 3, 6}
    };
    // cout << "1D Array : ";
    // printVec(arr);
    // // sort(arr.begin(), arr.end()) for sorting in increasing order
    // sort(arr.begin(), arr.end(), myComp); //for sorting in decreasing order
    // cout << "After sorting : " ;
    // printVec(arr);
    cout << "2D Array : " << endl;
    printvv(arr1);
    // sort(arr1.begin(), arr1.end()); according to the zeroth index
    sort(arr1.begin(), arr1.end(), myComp1); //sorting according to first index
    
    cout << "After sorting :" << endl;
    printvv(arr1);
    return 0;
}