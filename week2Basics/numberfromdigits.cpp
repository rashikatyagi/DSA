#include<iostream>
using namespace std;

int NumberFromDigits(int n)
{
    int number = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        int digit;
        cout << "Enter digit : ";
        cin >> digit;
        number = number*10 + digit; 
    }
    return number;
}

int main()
{
    int numberOfDigits;
    cout << "Enter the number of digits : ";
    cin >> numberOfDigits;
    int number = NumberFromDigits(numberOfDigits);
    cout << "The number created is : " << number << endl;
    return 0;
}