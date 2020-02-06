#include<iostream>
using namespace std;

int sumOfDigits(int n) {
    // Write your code here
    if (n == 0)
        return 0;
    int ans = sumOfDigits(n / 10);
    
    return (n % 10 + ans );

}



int main(){
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;

}

