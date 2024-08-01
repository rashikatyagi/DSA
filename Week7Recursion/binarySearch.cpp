#include<iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &nums, int start, int end, int target){
    if(start > end) return -1; 
    int mid = start + (end - start) / 2;
    if(nums[mid] == target) return mid;
    if(nums[mid] < target) return BinarySearch(nums, mid + 1, end,target);
    else return BinarySearch(nums, start, mid - 1, target);
}

int main()
{
    vector<int> arr;
    arr.push_back(10);
    // arr.push_back(23);
    // arr.push_back(40);
    // arr.push_back(42);
    // arr.push_back(50);
    // arr.push_back(79);
    // arr.push_back(83);
    int target = 101;
    int ans = BinarySearch(arr, 0, arr.size() - 1, target);
    if(ans != -1) cout << "Present at index : " << ans << endl;
    else cout << "Not Present" << endl;
    return 0;
}