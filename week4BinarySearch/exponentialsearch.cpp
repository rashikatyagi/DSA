#include<iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &arr, int start, int end, int target){
    int mid = 0;
    while(start <= end){
        mid = start + (end - start) / 2;
        if(arr[mid] == target) return mid;
        else if(target < arr[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int ExponentialSearchInUnboundedArray(vector<int> &arr, int target){
    if(arr[0] == target) return 0;
    int i = 1;
    while(arr[i] <= target){
        i = i * 2;
    }
    if(arr[i / 2] == target) return i/2;
    else return BinarySearch(arr, i/2, i, target);
}

int ExponentialSearch(vector<int> &arr, int target){
    if(target == arr[0]) return 0;
    int n = arr.size();
    int i = 1;
    while(i < n && target >= arr[i]){
        i = i * 2;
    }
    if(arr[i / 2] == target) return i/2;
    else return BinarySearch(arr, i/2, i, target);
}

void printArray(vector<int> &arr){
    for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;
    arr.push_back(3);
    // arr.push_back(4);
    // arr.push_back(5);
    // arr.push_back(6);
    // arr.push_back(11);
    // arr.push_back(13);
    // arr.push_back(14);
    // arr.push_back(15);
    // arr.push_back(56);
    // arr.push_back(70);
    printArray(arr);
    int target = 3;
    int ans = ExponentialSearch(arr, target);
    if(ans == -1) cout << "Element not present" << endl;
    else cout << "Element present at index : " << ans << endl;
    return 0;
}