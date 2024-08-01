#include<iostream>
using namespace std;

//this function returns the right position of the selected pivot element
int partition(int arr[], int start, int end)
{
    //select the pivot element
    int pivot = arr[start];

    //check how many elements in the array are less than the pivot element to get its right position
    int count = 0;
    for(int i = start+1 ; i <= end ; i++)
    {
        if(arr[i] < pivot)
            count++;
    }

    //pivot index
    int pivotIndex = start + count;

    //swapping the element at pivot index with the pivot element
    swap(arr[start], arr[pivotIndex]);

    //correcting the positions of left and right partitions
    int i = start, j = end;
    while(i < pivotIndex && j > pivotIndex)
    {
        //traverse till you get an element greater than pivot
        while(arr[i] < pivot)
            i++;
        
        //traverse till you get an element less than pivot
        while(arr[j] > pivot)
            j--;

        //when you get them, swap them
        swap(arr[i], arr[j]);
    }

    //after the above loop, all the elements at the left of pivot are less than pivot and
    //all the elements at the right of pivot are greater than pivot, now we can return the pivot index
    return pivotIndex;
}

void quicksort(int arr[], int start, int end)
{
    //base case
    if(start >= end)
    {
        return;
    }

    //find the right index of the pivot element where all elements in the left are smaller
    //and all elements at right are greater
    int p = partition(arr, start, end);

    //now sort the left part of the partition 
    quicksort(arr, start, p-1);

    //now sort the right part of the partition
    quicksort(arr, p+1, end);
}

void printArray(int arr[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {7, 9, 5, 7, 2, 1, 20, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Initial array : ";
    printArray(arr, size);

    
    quicksort(arr, 0, size - 1);

    cout << "After sorting : ";
    printArray(arr, size);
    return 0;
}