#include<iostream>
#include<string.h>
using namespace std;

template <typename T>
class stack{        
    T *data;
    int top;

public:
    stack(){
        data = new int[1000];
        top = -1;
    }

    void push(T element){
        top = top + 1;
        data[top] = element;
    }

    void pop(){
        top = top - 1;
    }

    T top(){
        return data[top];    
    }

    int size(){
        return top + 1;
    }

};

int countBracketReversals(char input[]){

    stack<char> s;    
    if(strlen(input) %2)
        return -1;
    
    int len = strlen(input);
    for(int i = 0 ; i < len; i++)
    {
        if(input[i] == '{')
            s.push(input[i]);
        
        if(input[i] == '}')
        {
            if(s.empty())
                s.push(input[i]);
            
            else{
                if(s.top() == '{')
                    s.pop();

                else
                    s.push(input[i]);
            }
        }
    }
    int ctr = 0;
    char c1 , c2;
    
    while(!s.empty()){

        c1 = s.top();
        s.pop();

        c2 = s.top();
        s.pop();

        if(c1 == c2)
            ctr += 1;
        else
            ctr += 2;
    }
    
    return ctr;
}

int main(){

}

