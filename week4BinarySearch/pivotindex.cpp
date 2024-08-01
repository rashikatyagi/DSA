#include<iostream>
#include <vector>
using namespace std;

void print(vector<int> arr){
    for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findPivotIndex(vector<int> arr){
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;
    while (start <= end)
    {
        if(start == end) return start;
        else if(mid != n - 1 && arr[mid] > arr[mid + 1]) return mid;
        else if(mid != 0 && arr[mid] < arr[mid - 1]) return mid - 1;
        else if(arr[mid] < arr[0]) end = mid - 1;
        else start = mid + 1;
        
        //update mid
        mid = start + (end - start)/2;
    }
    return -1;
}

int main()
{
    vector<int> arr;
    arr.push_back(18);
    arr.push_back(19);
    arr.push_back(110);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(10);
    arr.push_back(15);
    cout << "Array is : ";
    print(arr);
    cout << "Pivot index is : " << findPivotIndex(arr) << endl;
    return 0;
}