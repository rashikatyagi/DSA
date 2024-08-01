// NEW APPROACH OF QUICK SORT

#include<iostream>
#include <vector>
using namespace std;

void QuickSort(int arr[], int start, int end){
    //base case
    if(start >= end) return;

    //processing
    int pivot = end;
    int i = start - 1;
    int j = start;
    while(j < pivot){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);

    //recursive call
    QuickSort(arr, start, i-1);
    QuickSort(arr, i+1, end);
}

void printArray(int arr[], int size){
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {7, 2, 1, 8, 6, 5, 4};
    int size = 7;
    cout << "Array before : ";
    printArray(arr, size);
    cout << "Array after : ";
    QuickSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}