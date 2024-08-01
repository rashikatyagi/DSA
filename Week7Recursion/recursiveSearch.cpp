#include<iostream>
#include <vector>
using namespace std;

bool RecursiveSearch(vector<int> &arr, int index, int target){
    if(index >= arr.size()) return false;
    if(arr[index] == target) return true;
    return RecursiveSearch(arr, ++index, target); 
}

int main()
{
    vector<int> arr;
    arr.push_back(20);
    arr.push_back(23);
    arr.push_back(40);
    arr.push_back(12);
    arr.push_back(10);
    arr.push_back(19);
    arr.push_back(43);
    int target = 11;
    bool ans = RecursiveSearch(arr, 0, target);
    cout << target << " present in array : " << ans << endl;
    return 0;
}