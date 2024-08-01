#include<iostream>
using namespace std;

void print(int arr[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//counting method
void Sort0and1(int arr[], int n)
{
    int countZero = 0;
    int countOne = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] == 0) countZero++;
        else countOne++;
    }

    int index = 0;
    while(countZero--)
    {
        arr[index++] = 0; 
    }
    while(countOne--)
    {
        arr[index++] = 1;
    }
}

//two pointer method
void Sort0and1usingTwoPointer(int arr[], int n)
{
    int pointer1 = 0;
    int pointer2 = n - 1;
    while(pointer1 < pointer2)
    {
        if(arr[pointer1] == 1)
        {
            swap(arr[pointer1], arr[pointer2]);
            --pointer2;
        }
        else
        {
            pointer1++;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Array before sorting : ";
    print(arr, size);

    cout << "Array after sorting with counting method: "; 
    Sort0and1(arr, size);
    print(arr, size);

    cout << "Array after sorting with two pointers method: "; 
    Sort0and1usingTwoPointer(arr, size);
    print(arr, size);

    return 0;
}