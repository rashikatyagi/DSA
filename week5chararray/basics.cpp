#include<iostream>
using namespace std;

int lengthString(char ch[]){
    int count = 0;
    for(int i = 0 ; ch[i] != '\0' ; i++){
        count++;
    }
    return count;
}

bool isPalindrome(char ch[], int n){
    for(int i = 0, j = n - 1 ; i < n / 2 ; i++, j--){
        if(ch[i] != ch[j]) return false;
    }
    return true;
}

void reverseArray(char ch[], int n){
    for(int i = 0, j = n - 1 ; i < n / 2 ; i++, j--)
        swap(ch[i], ch[j]);
}

int main()
{
    char ch[50];
    // cout << "Enter character array : " ;
    // cin >> ch;  // using this method we can store only words and not sentences because
    // // space, tab and enter are delimiters for cin
    // cout << "Character array is : ";
    // cout << ch << endl;
    
    // for storing sentences, we can use cin.getline function
    cout << "Enter string : " << endl;
    cin.getline(ch, 50);
    cout << "Char array : ";
    cout << ch << endl;
    int n = lengthString(ch);
    cout << "Length of string : " << n << endl;
    if(isPalindrome(ch, n) == true) cout << "Palindrome" << endl;
    else cout << "Invalid palindrome" << endl;
    cout << "String after reversing : " ;
    reverseArray(ch, n);
    cout << ch << endl;
    return 0;
}