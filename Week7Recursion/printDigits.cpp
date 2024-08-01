// Head Recursion

#include<iostream>
using namespace std;

void printDigits(int num){
    if(num <= 0) return;
    printDigits(num / 10);
    cout << num % 10 << " ";
}

int main()
{
    cout << "Enter the number : ";
    int num;
    cin >> num;
    printDigits(num);
    return 0;
}