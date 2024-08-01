#include<iostream>
#include <vector>
using namespace std;

void print(vector<int> nums){
    for(int i = 0 ; i < nums.size() ; i++)
        cout << nums[i] << " ";
    cout << endl;
}

int FindOddOccuringElement(vector<int> nums){
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while(start <= end){
        if(start == end) return start;
        else if(mid % 2 == 0){
            if(mid != n - 1 && nums[mid] == nums[mid + 1]) start = mid + 2;
            else end = mid;
        }
        else{
            if(mid != 0 && nums[mid] == nums[mid - 1]) start = mid + 1;
            else end = mid - 1;  //because the answer cannot lie on odd index
        }

        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(4);
    cout << "Array : ";
    print(nums);
    cout << "Element occuring odd number of times is : " << FindOddOccuringElement(nums) << endl;
    return 0;
}