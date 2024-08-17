#include<iostream>
#include <queue>
#include<vector>
using namespace std;

class Info{
    public:
    int data;
    int row;
    int col;

    Info(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(Info* a, Info* b){
        return a->data > b->data; // this means that the priority of a->data is greater than b->data.
        // and the the elements with higher priority are removed before. So, this means a is smaller than b.
    }
};

vector<int> mergeKsortedArray(int arr[][4], int k){
    vector<int> ans;
    priority_queue<Info*, vector<Info*>, compare> pq;
    for(int i = 0 ; i < k ; i++){
        Info* temp = new Info(arr[i][0], i, 0);
        pq.push(temp);
    }
    while(!pq.empty()){
        Info* front = pq.top();
        pq.pop();
        int topElement = front->data;
        int topRow = front->row;
        int topCol = front->col;
        ans.push_back(topElement);
        if(topCol + 1 < 4){
            Info* temp = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
            pq.push(temp);
        }
    }
    return ans;
}

void printArray(vector<int> &arr){
    for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[3][4] = {
        {1, 4, 8, 11},
        {2, 3, 6, 10},
        {5, 7, 12, 14}
    };
    vector<int> ans = mergeKsortedArray(arr, 3);
    printArray(ans);
    return 0;
}