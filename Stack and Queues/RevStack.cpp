// #include <stack>
#include <iostream>
using namespace std;
// #include "solution.h"



void reverseStack(stack<int> &input, stack<int> &extra) {
    // Write your code here
    if(input.size() == 0 || input.size() == 1)
        return;
    
    int element = input.top();
    input.pop();
    
    reverseStack(input , extra);
    
    while(input.size() != 0){
        int x = input.top();
        input.pop();
        extra.push(x);
    }
    input.push(element);
    
    while(extra.size() != 0){
        int y = extra.top();
        extra.pop();
        input.push(y);
    }

}


int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
        cin >> val;
        s1.push(val);
    }
    reverseStack(s1, s2);
    while(!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
}