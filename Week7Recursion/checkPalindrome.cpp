#include<iostream>
#include <string>
using namespace std;

bool checkPalindromeRE(string s, int start, int end){
    if(start >= end) return true;
    if(s[start] != s[end]) return false;
    return checkPalindromeRE(s, ++start, --end);
}

int main()
{
    string s = "11";
    bool ans = checkPalindromeRE(s, 0, s.length() - 1);
    if(ans == 1) cout << "Is Palindrome" << endl;
    else cout << "Not Palindrome" << endl;
    return 0;
}