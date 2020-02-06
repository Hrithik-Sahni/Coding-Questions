#include<string.h>
#include<bits/stdc++.h>
#include <iostream>
using namespace std;


// Change in the given string itself. So no need to return or print anything

#include<bits/stdc++.h>

void removeX(char input[]) {
     

    if(input[0] == '\0') 
        return;
    
   removeX(input+1);
    
    if(input[0] == 'x'){
        int i;
        int len = strlen(input);
        for(i = 0;i<len-1;i++)
            input[i] = input[i+1];
        
        input[i] = '\0';
    }
}
int main() {

    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}

    
