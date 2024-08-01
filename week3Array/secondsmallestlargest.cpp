#include<iostream>
#include<vector>
using namespace std;

void findSecondSmallestAndLargestElement1(vector<int>&nums){
    int ans1 = INT_MIN;
    int ans2 = INT_MAX;
    int n = nums.size();
    if(n == 0 || n == 1){
        cout << -1 << " " << -1 << endl;
        return;
    }
    else if(n == 2){
        cout << nums[n - 1] << " " << nums[0] << endl;
        return;
    }
    int max = INT_MIN, min = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        if(nums[i] > max) max = nums[i];
        if(nums[i] < min) min = nums[i];
    }
    for(int i = 0 ; i < n ; i++){
        if(nums[i] != max && nums[i] > ans1) ans1 = nums[i];
        if(nums[i] != min && nums[i] < ans2) ans2 = nums[i];
    }
    if(ans1 == INT_MIN) ans1 = -1;
    if(ans2 == INT_MAX) ans2 = -1;
    cout << ans1 << " " << ans2 << endl;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    // arr.push_back(7);
    // arr.push_back(7);
    // arr.push_back(5);
    findSecondSmallestAndLargestElement1(arr);
    return 0;
}