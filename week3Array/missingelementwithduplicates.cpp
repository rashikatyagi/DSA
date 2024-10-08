#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

// vector <int> MissingElementsWithDuplicates(vector<int> nums)
// {
//     vector<int> ans;
//     int n = nums.size();
//     for(int i = 0 ; i < n ; i++)
//     {
//         if(nums[i] <= n - 1 && nums[ abs(nums[i]) ] > 0)
//             nums[abs(nums[i])] *= -1;
//     }
//     for(int i = 1 ; i < n ; i++)
//     {
//         if(nums[i] > 0)
//             ans.push_back(i);
//     }
//     return ans;
// }

vector <int> MissingElementsWithDuplicates1(vector<int> nums)
{
    vector<int> ans;
    int n = nums.size();
    for(int i = 0 ; i < n ; i++)
    {
        if(nums[ abs(nums[i]) - 1 ] > 0)
            nums[abs(nums[i]) - 1 ] *= -1;
    }
    for(int i = 1 ; i < n ; i++)
    {
        if(nums[i] > 0)
            ans.push_back(i + 1);
    }
    return ans;
}

vector<int> MissingElementsWithDuplicates2(vector<int> nums){
    vector<int> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0 ; i < nums.size(); i++){
        if(nums[i] != i  + 1)
            ans.push_back(i + 1);
    }
    return ans;
}


void PrintArray(vector <int> nums)
{
    for(int i = 0 ; i < nums.size() ; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    // vec.push_back(3);
    // vec.push_back(5);
    // vec.push_back(3);
    // vec.push_back(4);
    // vec.push_back(4);
    // vec.push_back(7);
    cout << "Array : ";
    PrintArray(vec);
    cout << "Missing elements : ";
    vector <int> ansArray = MissingElementsWithDuplicates1(vec);
    // vector <int> ansArray = MissingElementsWithDuplicates2(vec);
    PrintArray(ansArray);
    return 0;
}
