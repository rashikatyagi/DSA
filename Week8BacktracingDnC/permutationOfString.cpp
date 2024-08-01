#include<iostream>
using namespace std;

void PermutationOfString(string & s, int index)
{
    //base case
    if(index >= s.length()){
        cout << s << " ";
        return;
    }

    for(int j = index ; j < s.length() ; j++){
        swap(s[index], s[j]);
        //recursion
        PermutationOfString(s, index+1);
        //backtracking
        swap(s[index], s[j]);
    }
}

int main()
{
    string s = "abx";
    PermutationOfString(s, 0);
    return 0;
}