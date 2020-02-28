#include <iostream>
using namespace std;
// #include "solution.h"
template <typename T>

class Stack{
    T *s;
    int top;
    
    public:
    
    Stack(){
        s = new T[10000000];
        top = -1;
    }
    void push(T data)
    {
        top = top + 1;
        s[top] = data;
    }
    void pop(){
        top = top - 1;
    }
    
    int size(){
        if(top == -1)
            return 0;
        
        return (top + 1);
    }
    
    T topgive(){
        return s[top];
    }
};

bool checkRedundantBrackets(char *input) {
    // Write your code here
    Stack<char> s;
    int i = 0;
    int ctr;
    while(input[i] != '\0')
    {
        
        if(input[i] == '('){
            // ctr = 0;
            while(input[i] != ')'){
                s.push(input[i]);
                i++;
            }
        }

        if(input[i] == ')'){
            ctr = 0;
            while(s.topgive() != '('){
                ctr++;
                s.pop();
                }
            s.pop();
    }
        
        if(ctr == 0)
            return true;
        
        i++;
    }
    
    return false;
}


int main() {
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

}
