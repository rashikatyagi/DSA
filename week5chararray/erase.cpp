#include<iostream>
#include <string>
using namespace std;

void erase(string& s, int start, int length){
    //invalid conditions
    int n = s.length();
    if(start < 0 || start >= n) return;

    if(start + length > n - 1){
        s.resize(start);
        return;
    }

    //shifting characters
    
    int end = start + length;
    for(int i = end ; i < n ; i++){
        s[i - length] = s[i];
    }

    //resizing the string
    s.resize(n - length);
}

int main()
{
    string s = "rashika";
    cout << "String before : " << s << endl;
    int startingIndex = 4;
    int length = 5;

    erase(s, startingIndex, length);
    cout << "String after : " << s << endl;
    return 0;
}