#include<iostream>
using namespace std;

void merge(int arr[], int start, int end)
{
    int mid = start + (end - start)/2;

    int lengthFirst = mid - start + 1;
    int lengthSecond = end - mid;
    int lengthArray = end - start + 1;

    //create two arrays
    int* first = new int[lengthFirst]; 
    int* second = new int[lengthSecond];

    //copying the data from original array to the first created array
    int k = start;
    for(int i = 0 ; i < lengthFirst ; i++)
    {
        first[i] = arr[k];
        k++;
    }

    //copying the data from original array to the second created array
    int l = mid + 1;
    for(int i = 0 ; i < lengthSecond ; i++)
    {
        second[i] = arr[l];
        l++;
    }

    //starting index of the original array is given
    int indexOriginal = start;

    //--------YAHA GALTI KAROGE---------
    //these indexes are created to traverse on the particular arrays
    int indexFirst = 0;
    int indexSecond = 0;
    
    while(indexFirst < lengthFirst && indexSecond < lengthSecond)
    {
        if(first[indexFirst] < second[indexSecond])
        {
            arr[indexOriginal] = first[indexFirst];
            indexFirst++;
            indexOriginal++;
        }
        else
        {
            arr[indexOriginal] = second[indexSecond];
            indexSecond++;
            indexOriginal++;
        }
    }

    //for remaining part of arrays
    while(indexFirst < lengthFirst)
    {
        arr[indexOriginal] = first[indexFirst];
        indexFirst++;
        indexOriginal++;
    }
    while(indexSecond < lengthSecond)
    {
        arr[indexOriginal] = second[indexSecond];
        indexSecond++;
        indexOriginal++;
    }

    //deleting the space dynamically allocated
    delete[] first;
    delete[] second;
}

void mergesort(int arr[], int start, int end)
{
    //base case
    //inappropriate case
    if(start > end)
    {
        cout << "Cannot sort" << endl;
        return;
    }
    //single element case
    if(start == end)
    {
        return;
    }

    //finding the mid of the array so that we can split it into two
    int mid = start + (end - start)/2;

    //splitting the array into two
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);

    merge(arr, start, end);

}

void print_array(int arr[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 38, 34, 23, 89, 45};
    print_array(arr, 6);

    mergesort(arr, 0, 6);
    print_array(arr, 6);
    return 0;
}