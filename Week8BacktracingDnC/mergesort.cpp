#include<iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int end){
    int mid = start + (end - start) / 2;
    vector<int> arr1;
    vector<int> arr2;
    for(int i = start ; i <= end ; i++){
        if(i <= mid) arr1.push_back(arr[i]);
        else arr2.push_back(arr[i]);
    }
    int indexMainArray = start;
    int index1 = 0;
    int index2 = 0;
    while(index1 < arr1.size() && index2 < arr2.size()){
        if(arr1[index1] < arr2[index2]){
            arr[indexMainArray++] = arr1[index1++]; 
        }
        else arr[indexMainArray++] = arr2[index2++];
    }
    while(index1 < arr1.size()){
        arr[indexMainArray++] = arr1[index1++];
    }
    while(index2 < arr2.size()){
        arr[indexMainArray++] = arr2[index2++];
    }
}

void MergeSort(vector<int> &arr, int start, int end){
    // base case
    // if array is empty
    if(start > end) return;
    // single element case
    if(start == end) return;

    int mid = start + (end - start) / 2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

void PrintArray(vector<int> &arr){
    for(auto x : arr){
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;
    arr.push_back(70);
    arr.push_back(15);
    // arr.push_back(20);
    // arr.push_back(10);
    // arr.push_back(45);
    // arr.push_back(65);
    cout << "Array before : ";
    PrintArray(arr);
    cout << "Array after : ";
    MergeSort(arr, 0, arr.size() - 1);
    PrintArray(arr);
    return 0;
}