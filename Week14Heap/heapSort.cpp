#include<iostream>
using namespace std;

void printHeap(int* arr, int size){
            for(int i = 1 ; i < size ; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }        

void heapify(int* arr, int n, int index){  //here, we have to heapify the index
    int largestIndex = index;
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;

    //get the largest among largestIndex, left and right index
    if(leftIndex <= n && arr[leftIndex] > arr[largestIndex]) largestIndex = leftIndex;
    if(rightIndex <= n && arr[rightIndex] > arr[largestIndex]) largestIndex = rightIndex;

    if(index != largestIndex){
        //bring the largest element to right position
        swap(arr[largestIndex], arr[index]);
        heapify(arr, n, largestIndex);
    }
} 

void buildHeap(int* arr, int n){
    for(int i = n / 2 ; i > 0 ; i--){
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    int index = 1;
    while(n != 1){
        swap(arr[index], arr[n--]);
        heapify(arr, n, index);
    }
}

int main()
{
    int arr[] = {0, 10, 20, 5, 11, 6};
    int size = 6;
    cout << "Before sorint : ";
    buildHeap(arr, size);
    printHeap(arr, size);
    cout << "After sorting : " ;
    heapSort(arr, size);
    printHeap(arr, size);
    return 0;
}