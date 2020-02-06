#include<string.h>
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void replacePi(char input[]) {
	// Write your code here
    if(input[0] == '\0')
        return;
    
    replacePi(input + 1);
    
    if(input[0] == 'p' && input[1] == 'i')
    {
        input[0] = '3';
        input[1] = '.';
        int i;
        int l = strlen(input);
        for(i = l; i >= 2; i -- )
        {
            input[i + 2]=input[i];
        }
        input[2] = '1';
        input[3] = '4';
    }
}

int main()
{
  char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}