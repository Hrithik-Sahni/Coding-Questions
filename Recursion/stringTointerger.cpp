#include<math.h>
#include<bits/stdc++.h>
using namespace std;

int stringToNumber(char input[]) {
    // Write your code here
    
    if(strlen(input) == 1)
        return(input[0] - 47);
    
    int ans = stringToNumber(input + 1);
    
    int x = input[0] - 48 ;  //ASCII VALUES OF 0 
    
    return( x * pow(10 , strlen(input) - 1) + ans ); 
    
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
