#include<iostream>
#include <vector>
using namespace std;

void MoveNegativeToOneSide(vector <int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while(low < high)
    {
        if(nums[low] > 0)
        {
            swap(nums[low], nums[high]);
            high--;
        }
        else
        {
            low++;
        }
    }

}

void PrintArray(vector<int> nums)
{
    for(int i = 0 ; i < nums.size() ; i++)
    {
        cout << nums.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    vector <int> nums;
    nums.push_back(-12);
    nums.push_back(-11);
    nums.push_back(-13);
    nums.push_back(-5);
    // nums.push_back(6);
    // nums.push_back(-7);
    // nums.push_back(-15);
    // nums.push_back(56);
    // nums.push_back(3);
    // nums.push_back(-72);
    cout << "Array before : ";
    PrintArray(nums);
    MoveNegativeToOneSide(nums);
    cout << "Array after : ";
    PrintArray(nums);
    return 0;
}