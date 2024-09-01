#include<iostream>
using namespace std;

// brute force approach
int gcd1(int a, int b){
    int gcd = 1;  //always 1
    for (int i = 2 ; i <= min(a, b) ; i++)
    {
        if(a % i == 0 && b % i == 0){
            gcd = i;
        }
    }
    return gcd;
}

// better approach
int gcd2(int a, int b){
    int gcd = 1;  //always 1
    for (int i = min(a, b) ; i >= 2 ; i--)
    {
        if(a % i == 0 && b % i == 0){
            gcd = i;
            break;
        }
    }
    return gcd;
}

// euclidean algorithm
int gcd_euclideanAlgorithm(int a, int b){
    while(a > 0 && b > 0){
        if(a > b) a = a % b;
        else b = b % a;
    }
    if(a == 0) return b;
    else return a;
}

int gcd_euclideanAlgorithmRE(int a, int b){
    // base case
    if(a == 0) return b;
    if(b == 0) return a;

    // recursive steps
    if(a > b) return gcd_euclideanAlgorithmRE(a % b, b);
    else return gcd_euclideanAlgorithmRE(a, b % a);
}

int main()
{
    int a = 52, b = 10;
    cout << gcd1(a, b) << endl;
    cout << gcd2(a, b) << endl;
    cout << gcd_euclideanAlgorithm(a, b) << endl;
    cout << gcd_euclideanAlgorithmRE(a, b) << endl;
    return 0;
}