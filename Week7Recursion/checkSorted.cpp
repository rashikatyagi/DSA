#include<iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> nums, int index){
    if(index == nums.size()) return true;
    if(nums[index] < nums[index - 1]) return false;
    return checkSorted(nums, index + 1);
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(12);
    arr.push_back(104);
    arr.push_back(196);
    arr.push_back(438);
    int index = 1; //start the index from 1
    bool ans = checkSorted(arr, index);
    cout << ans << endl;   
    return 0;
}