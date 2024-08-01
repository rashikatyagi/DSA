#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector <int> &vec)
{
    int n = vec.size();
    int minIndex;
    for(int i = 0 ; i < n-1 ; i++)
    {
        minIndex = i;
        for(int j = i+1 ; j < n ; j++)
        {
            if(vec[j] < vec[minIndex])
                minIndex = j;
        }
        swap(vec[i], vec[minIndex]);
    }
}

int main()
{
    vector <int> arr;
    arr.push_back(55);
    arr.push_back(44);
    arr.push_back(33);
    arr.push_back(22);
    arr.push_back(11);
    arr.push_back(9);
    for(int i = 0 ; i < arr.size() ; i++)
        cout << arr[i] << " ";
    cout << endl;
    selectionSort(arr);
    for(int i = 0 ; i < arr.size() ; i++)
        cout << arr[i] << " ";
    cout << endl;
}