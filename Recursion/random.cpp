#include<string.h>
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

bool helper(char arr[], int start , int end )
{
    if(end == start)
        return true;
    
    if(arr[start] != arr[end] )
        return false;
    
    if(start < end + 1)
        return helper(arr, start + 1 , end - 1); 
    
    // return true;
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int end = strlen(input);
    int start = 0 ; 
    
    if(end == 0)
        return true;
    
    bool ans = helper(input , start , end - 1);
    return ans;
}


int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
