#include<iostream>
using namespace std;


bool helper(char arr[], int start , int end )
{
    if(arr[0] != arr[end-1])
        return false;
}


bool checkPalindrome(char input[]) {
    // Write your code here
    int end = sizeof(input);
    int start = 0 ; 
    if (end == 0 || end == 1)
        return true;

    bool ans = helper(input + 1 , start , end - 1);
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
