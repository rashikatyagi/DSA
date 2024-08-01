/*
Sum of minimum and maximum elements of all subarrays of size k.
Given an array of both positive and negative integers, the task is 
to compute sum of minimum and maximum elements of all sub-array of 
size k.
*/

#include<iostream>
#include<queue>
using namespace std;

// int sumOfMinMaxInSubarray(int* arr, int n, int k){
//     int sum = 0;

//     //find all the subarrays
//     for(int i = 0 ; i < n ; i++){
//         int length = 0;
//         for(int j = i ; j < n ; j++){
//             length++;
            
//             if(length == k){
//                 // get the minimum and maximum of this subarray
//                 int maxi = INT_MIN;
//                 int mini = INT_MAX;
//                 for(int x = i ; x <= j ; x++){
//                     maxi = max(maxi, arr[x]);
//                     mini = min(mini, arr[x]);
//                 }
//                 sum += maxi + mini;
//                 break;
//             }
//         }
//     }
//     return sum;
// }

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int size = 7;
    int k = 4;
    cout << "Answer : " << sumOfMinMaxInSubarray(arr, size, k) << endl;
    return 0;
}