#include<iostream>
#include <string>
using namespace std;

void findLastOccLtoR(string s, char p, int index, int &ans){
    int n = s.length();
    if(index >= n){
        return;
    }
    if(s[index] == p) ans = index;
    findLastOccLtoR(s, p, ++index, ans);
}

int findLastOccRtoL(string s, char p, int index){
    if(index < 0) return -1;
    if(s[index] == p) return index;
    return findLastOccRtoL(s, p, index - 1);
}

int main()
{
    string s = "GeeksForGeeks";
    char p = 'e';
    // int index = findLastOccRtoL(s, p, s.length() - 1);
    int index = -1;
    findLastOccLtoR(s, p, 0, index);
    cout << index << endl;
    return 0;
}