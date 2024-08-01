#include<iostream>
using namespace std;

int FindUnique(int arr[], int n)
{
    int FinalAns = 0;

    for(int i = 0 ; i < n ; i++)
    {
        FinalAns = FinalAns ^ arr[i];
    }

    return FinalAns;
}

int getUnique(int arr[], int n) {
  int ans = 0;
  for(int i=0; i<n; i++) {
    ans = ans^arr[i];
  }
  return ans;
}

int main()
{
    // int arr[] = {10, 1, 12, 34, 10, 32, 12, 34, 32, 1};
    int arr[] = {2,10,11,10,2,13,15,13,15};
    int size = 9;
    int uniqueElemenet = FindUnique(arr, size);
    cout << "Unique element is : " << uniqueElemenet << endl; 
    return 0;
}