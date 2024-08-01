#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> nums){
    for(int i = 0 ; i < nums.size() ; i++)
        cout << nums[i] << " ";
    cout << endl;
}

int NearlySortedArray(vector<int> nums, int target){
    int n = nums.size();
    int start = 0 ;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while(start <= end){
        if(nums[mid] == target) return mid;
        else if(mid != 0 && nums[mid - 1] == target) return mid - 1;
        else if(mid != n - 1 && nums[mid + 1] == target) return mid + 1;
        else if(nums[mid] < target) start = mid + 2;
        else end = mid - 2;

        mid = start + (end - start)/2;
    }
    return -1;
}

int main()
{
    vector<int> nums;
    nums.push_back(20);
    // nums.push_back(10);
    // nums.push_back(30);
    // nums.push_back(50);
    // nums.push_back(40);
    // nums.push_back(70);
    // nums.push_back(60);
    int target = 2;
    cout << "Array : ";
    print(nums);
    cout << "Target element " << target << " present at : " << NearlySortedArray(nums, target) << endl;
    return 0;
}