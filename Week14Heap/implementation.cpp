#include<iostream>
using namespace std;

class Heap{
    public:
        int* arr;
        int capacity;
        int size;
        Heap(){
            size = 0;
        }
        Heap(int capacity){
            arr = new int[capacity];
            this->capacity = capacity;
            this->size = 0;
        }
        void insert(int element){
            if(size == capacity) return;
            //incrementing the size to use 1 based indexing 
            size++;
            //inserting element
            int index = size;
            arr[index] = element;
            //checking the correct position of element
            while(index > 1){
                int parentIndex = index / 2;
                if(arr[index] > arr[parentIndex]){
                    swap(arr[index], arr[parentIndex]);
                    index = parentIndex; //now to check the position of parent 
                }
                else break; //otherwise infinite loop
            }
        }
        void printHeap(){
            for(int i = 1 ; i <= size ; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        int deleteInHeap(){
            int answer = arr[1];
            arr[1] = arr[size--];
            int index = 1;
            int largest = 1;
            while(index < size){
                int left = 2 * index;
                int right = 2 * index + 1;
                if(left <= size && arr[largest] < arr[left]){
                    largest = left;
                }
                if(right <= size && arr[largest] < arr[right]){
                    largest = right;
                }
                
                if(index == largest) break;
                else{
                    swap(arr[index], arr[largest]);
                    index = largest;
                }
            }
            return answer;
        }
};

int main()
{
    Heap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);
    h.printHeap();
    h.deleteInHeap();
    h.printHeap();
    return 0;
}