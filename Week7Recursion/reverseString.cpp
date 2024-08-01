#include<iostream>
using namespace std;

void reverseString(string &s, int index){
    int n = s.length();
    if(index >= n / 2) return;
    swap(s[index], s[n - index - 1]);
    reverseString(s, ++index);
}

int main()
{
    string s = "rash";
    cout << "String is : " << s << endl;
    reverseString(s, 0);
    cout << "After reversing : " << s << endl;
    return 0;
}