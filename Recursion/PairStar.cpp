#include<string.h>
#include<bits/stdc++.h>
#include <iostream>
using namespace std;


// Change in the given string itself. So no need to return or print anything


void pairStar(char input[]) {
    // Write your code here
    if(input[0] == '\0')
        return;
    
    pairStar(input + 1);
    
    if(input[0] == input[1])
    {
        int l = strlen(input);
        
        for(int i = l ; i >= 1; i--)
        {
            input[i + 1] = input[i];
        }
         input [1] = '*';    
    }
}

int main()
{

   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;


}

    
