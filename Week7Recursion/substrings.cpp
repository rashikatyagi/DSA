#include<iostream>
#include <string>
using namespace std;

void FindSubsequence(string input, string output, int index){
    if(index >= input.length()){
        cout << output << endl;
        return;
    }

    //excluding current index
    FindSubsequence(input, output, index + 1);

    //including current index
    char ch = input[index];
    output.push_back(ch);
    FindSubsequence(input, output, index + 1);
}

int main()
{
    string input = "abcd";
    FindSubsequence(input, "", 0);
    return 0;
}