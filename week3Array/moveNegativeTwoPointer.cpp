#include<iostream>
using namespace std;

void moveNegativeElementsUsingTwoPointer(int *arr, int n){
    int start = 0;
    int end = n - 1;
    while(start < end){
        if(arr[start] < 0) start++;
        else swap(arr[start], arr[end--]);

        if(arr[end] > 0) end--;
        else swap(arr[start++], arr[end]);
    }
}

int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = 9;
    moveNegativeElementsUsingTwoPointer(arr, n);
    //printing array
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}