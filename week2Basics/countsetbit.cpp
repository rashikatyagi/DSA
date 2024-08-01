#include<iostream>
using namespace std;

int CountSetBit(int num)
{
    int count = 0;
    // while(num)
    // {
    //     int bit = num % 2;
    //     if(bit == 1) count++;
    //     num = num / 2;
    // }
    while(num)
    {
        if((num & 1) == 1) count++;
        num = num >> 1;
    }
    return count;
}

int main()
{
    int num;
    cout << "Enter the number : ";
    cin >> num;
    cout << "Number of set bits : " << CountSetBit(num) << endl;
    return 0;
}