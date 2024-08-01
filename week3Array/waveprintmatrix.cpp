#include<iostream>
#include <vector>
using namespace std;

void WavePrintMatrix(vector<vector<int> > arr)
{
    int row = arr.size();
    int col = arr[0].size();
    for(int i = 0 ; i < col ; i++){
        if(i % 2 == 0){
            for(int j = 0 ; j < row ; j++)
                cout << arr[j][i] << " ";
        }
        else{
            for(int j = row - 1 ; j >= 0 ; j--)
                cout << arr[j][i] << " ";
        }
    }
}

void printNormal(vector<vector<int> > arr){
    for(int i = 0 ; i < arr.size() ; i++){
        for(int j = 0 ; j < arr[0].size() ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int> > arr{
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 },
        { 17, 18, 19, 20 } 
    };
    cout << "Normal Matrix : " << endl;
    printNormal(arr);
    cout << "Wave Print : " ;
    WavePrintMatrix(arr);
    return 0;
}