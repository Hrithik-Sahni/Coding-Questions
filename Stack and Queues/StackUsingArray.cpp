#include<iostream>
#include <climits>
using namespace std;;

class Stack{

    int * data;
    int nextIndex;
    int capacity;

public:
    Stack(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    int size()      //Returns the number of elements in the Stack
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        if(nextIndex == 0)
            return true;

        return false;
    }

    void push(int element)
    {
        if(nextIndex == capacity){
            cout << "OverFlow" << endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex ++;
    }

    int pop()
    {
        if(isEmpty()){
            cout << "UnderFlow" << endl;
            return INT_MIN;
        }

        nextIndex -- ;  
        return data[nextIndex]; 
    }

    int top()
    {
        if(isEmpty()){
            cout << "Empty Stack";
            return INT_MIN;
        }

        return data[nextIndex - 1];
    }
};

int main()
{
    Stack s(4);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}