#include<iostream>
using namespace std;

int DivisionBS(int dividend, int divisor){
    //some default cases
    if(divisor == 0){
        cout << "Divisor cannot be zero!" << endl;
        return;
    }
    if(dividend < divisor) return 0;

    int start = 1;
    int end = dividend / 2;
    int mid = start + (end - start) / 2;
    while(start < end){
        if(mid * divisor == dividend) return mid;
        else if(mid * divisor < dividend) start = mid + 1;
        else end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return mid;
}

int main()
{
    int dividend = 15245;
    int divisor = 2;
    int answer = DivisionBS(dividend, divisor);
    cout << dividend << " divided by " << divisor << " is : " << answer << endl;
    return 0;
}