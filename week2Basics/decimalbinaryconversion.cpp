#include<iostream>
#include <cmath>
using namespace std;

int decimalToBinaryDIVISION(int num)
{
    int binaryNum = 0;
    int i = 0;
    while(num > 0)
    {
        int bit = num % 2;
        binaryNum = pow(10, i)*bit + binaryNum;
        i++;
        num /= 2;
    }
    return binaryNum;
}

int decimalToBinaryBITWISE(int num)
{
    int binaryNum = 0;
    int i = 0;
    while(num > 0)
    {
        int bit = num & 1;
        binaryNum = pow(10, i++)*bit + binaryNum;
        num = num >> 1;
    }
    return binaryNum;
}

int binaryToDecimalDIVISION(long long int binaryNum)
{
    int decimal = 0;
    int i = 0;
    while(binaryNum > 0)
    {
        int bit = binaryNum % 10;
        decimal = pow(2, i++)*bit + decimal;
        binaryNum /= 10;
    }
    return decimal;
}

int binaryToDecimalBITWISE(long long int binaryNum)
{
    int decimal = 0;
    int i = 0;
    while(binaryNum > 0)
    {
        int bit = binaryNum & 1;
        decimal = pow(2, i)*bit + decimal;
        i++;
        binaryNum = binaryNum >> 1;
    }
    return decimal;
}

int main()
{
    int num;
    cout << "Enter the decimal number : ";
    cin >> num;
    cout << "Binary representation(Division) : " << decimalToBinaryDIVISION(num) << endl;
    cout << "Binary representation(Bitwise) : " << decimalToBinaryBITWISE(num) << endl;
    int binaryNum;
    cout << "Enter binary number : ";
    cin >> binaryNum;
    cout << "Decimal conversion : " << binaryToDecimalDIVISION(binaryNum) << endl;
    cout << "Decimal conversion : " << binaryToDecimalBITWISE(binaryNum) << endl;
    return 0;
}