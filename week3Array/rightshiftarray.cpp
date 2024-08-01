#include<iostream>
using namespace std;

void print(int arr[], int n)
{
    for(int i = 0 ; i < n ; ++i)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void RightShiftArray(int arr[], int n)
{
    int lastElement = arr[n - 1];
    for(int i = n - 1 ; i > 0 ; --i)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = lastElement;
}

void KElementsRightShift(int arr[], int n, int k)
{
    int newArr[k];
    int index = n - 1;
    for(int i = 0 ; i < k ; i++)
    {
        newArr[i] = arr[index--];
    }
    for(int i = n - 1 ; i >= 0 ; --i)
    {
        arr[i] = arr[i - k];
    }
    for(int i = 0 ; i < k ; i++)
    {
        arr[i] = newArr[i];
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before shift : ";
    print(arr, size);

    cout << "Array after shift : ";
    RightShiftArray(arr, size);
    print(arr, size);

    int k;
    cout << "Enter k : " ;
    cin >> k;
    KElementsRightShift(arr, size, k);
    cout << "Array after shift : ";
    print(arr, size);
    return 0;
}