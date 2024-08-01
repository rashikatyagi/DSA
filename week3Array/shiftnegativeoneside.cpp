#include<iostream>
#include <vector>
using namespace std;

void PrintArray(vector <int> vec)
{
    for(auto it : vec)
    {
        cout << it << " ";
    }
    cout << endl;
}

void ShiftNegativeOneSide(vector <int> &arr)
{
    int n = arr.size();
    int pointer1 = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] < 0)
        {
            swap(arr[i], arr[pointer1]);
            pointer1++;
        }
    }
}

int main()
{
    vector <int> vec;
    vec.push_back(-1);
    vec.push_back(23);
    vec.push_back(-4);
    vec.push_back(-2);
    vec.push_back(25);
    vec.push_back(31);
    vec.push_back(9);
    vec.push_back(-6);
    vec.push_back(-35);
    cout << "Array before shifting negatives : ";
    PrintArray(vec);
    ShiftNegativeOneSide(vec);
    cout << "Array after shifting negatives : ";
    PrintArray(vec);
    return 0;
}