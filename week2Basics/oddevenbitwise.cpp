#include<iostream>
using namespace std;
/*
CONCEPT:-
In binary representation, if the number is even then its least significant bit
will always be 0 and if it is odd the it will be 1
*/

bool OddEvenBITWISE(int num)
{
    if((num & 1) == 0)
        return 0;
    else return 1;
}

int main()
{
    int num;
    cout << "Enter the number : ";
    cin >> num;
    if( OddEvenBITWISE(num) == 0 ) cout << "Even" << endl;
    else cout << "Odd" << endl;
    return 0;
}