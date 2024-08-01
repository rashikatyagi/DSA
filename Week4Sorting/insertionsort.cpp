#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector <int> &arr)
{
    int n = arr.size();
    //condition when only one element is present
    if(n == 1)
        return;
    
    //Start index from 1 because in insertion sort, we have to check the preceeding elements 
    for(int i = 1 ; i < n ; i++)
    {
        //to store the value that is being checked
        int key = arr[i];
        int j = i - 1;
        //for forward shifting
        while(j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        //at this position j is either -1 or at the index less than i, so that is why we are 
        //doing j+1
        arr[j + 1] = key;
    }
}

int main()
{
    vector <int> a;
    a.push_back(5);
    a.push_back(11);
    a.push_back(9);
    a.push_back(3);
    a.push_back(3);
    for(int i = 0 ; i < a.size() ; i++)
        cout << a[i] << " ";
    cout << endl;
    insertionSort(a);
    for(int i = 0 ; i < a.size() ; i++)
        cout << a[i] << " ";
    cout << endl;
}