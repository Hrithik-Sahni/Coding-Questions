#include<iostream>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string str[100] = { "" , "" , "abc", "def" , "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    int n1 = num / 10;
    int n2 = num % 10;

    if(num == 0)
    {    
        output[0] = "";
        return 1;
    }
    
    int countSmall = keypad(n1 , output);
    int n = (str[n2].size() - 1)*countSmall;
    int j = 0;
    
    for( int i = 0; i < n ; i++)
    {    
        output[i + countSmall] = output[i];  //Creating Copies of the result of recursion
    }
    for(int i = 0; i < str[n2].size()*countSmall; i ++)
    {
        if(i % str[n2].size() == 0)
        {
            j = j + 1;
        }
        output[i] = output[i] + str[n2][j];
        cout << output[i] << " ";
    }
    return (str[n2].size())*countSmall;        
}




    int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
