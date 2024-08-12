#include<iostream>
#include <queue>
using namespace std;

int getKthSmallestElement(vector<int> &arr, int k){
    // create a max heap of k elements
    priority_queue<int> pq;
    for(int i = 0 ; i < k ; i++){
        pq.push(arr[i]);
    }

    //for the next remaining elements, insert the elements in the max heap 
    //that are smaller than the top element.
    // 1--> Pop the top element   2--> Insert the element in the max heap
    //with this step only k elements that are smallest will be added in the max heap
    for(int i = k ; i < arr.size() ; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int getKthLargestElement(vector<int> &arr, int k){
    // create a max heap of k elements
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0 ; i < k ; i++){
        pq.push(arr[i]);
    }

    //for the next remaining elements, insert the elements in the max heap 
    //that are smaller than the top element.
    // 1--> Pop the top element   2--> Insert the element in the max heap
    //with this step only k elements that are smallest will be added in the max heap
    for(int i = k ; i < arr.size() ; i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(14);
    int k = 5;
    int ans = getKthSmallestElement(arr, k);
    cout << "Element is : " << ans << endl;
    return 0;
}