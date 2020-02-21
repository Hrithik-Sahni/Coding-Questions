#include<iostream>
#include <climits>
using namespace std;;

template <typename T>

class Stack{

    T * data;
    int nextIndex;
    int capacity;

public:
    Stack()
    {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
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

    void push(T element)
    {
        if(nextIndex == capacity){
            T * newData = new T[2*capacity];
            
            for(int i =0; i < capacity; i++)
                newData[i] = data[i];

            delete [] data;
            data = newData;
        }

        data[nextIndex] = element;
        nextIndex ++;
    }

    T pop()
    {
        if(isEmpty()){
            cout << "UnderFlow" << endl;
            return 0;
        }

        nextIndex -- ;  
        return data[nextIndex]; 
    }

    T top()
    {
        if(isEmpty()){
            cout << "Empty Stack";
            return 0;
        }

        return data[nextIndex - 1];
    }
};

int main()
{
    Stack <float> s;

    s.push(10.1);
    s.push(20.5);
    s.push(30.8);
    s.push(40.4);
    s.push(50.3);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}