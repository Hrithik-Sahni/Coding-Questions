#include<iostream>
using namespace std;

class DynamicArray{
    int* data;
    int capacity;
    int nextIndex;

public:
    DynamicArray()
    {
        capacity = 5;
        nextIndex = 0;
        data = new int[capacity];
    }

    DynamicArray(DynamicArray const &x)
    {
        this -> nextIndex = x.nextIndex;
        this -> capacity = x.capacity;
        //DEEP COPY
        this -> data = new int[x.capacity];
        for(int i = 0 ; i < nextIndex; i++)
            this -> data[i] = x.data[i];
    }

    void operator =(DynamicArray const &x){
        this -> nextIndex = x.nextIndex;
        this -> capacity = x.capacity;
        this -> data = new int[x.capacity];
        for(int i = 0 ; i < nextIndex; i++)
            data[i] = x.data[i];
    }
    void add(int element)
    {
        if(nextIndex == capacity )
        {
            int*data2 = new int[2*capacity];
            for(int i = 0 ; i < capacity; i++)
                data2[i] = data[i];
            delete [] data;
            data = data2;
            capacity*=2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int get(int i) const
    {
        if(i < nextIndex){
            return data[i];
        }
        return -1;
    }
    void add(int i , int element)
    {
        if(i < nextIndex)
            data[i] = element;
        else if(i == nextIndex)
        {
            add(element);
        }
        else{
            return;
        }


    }
    void print() const
    {
        for(int i = 0 ; i < nextIndex; i++)
            cout << data[i] << " ";
        cout << endl;
    }


};


int main()
{
    DynamicArray d;
    d.add(10);
    d.add(20);
    d.add(30);
    d.add(40);
    d.add(50);
    d.add(60);
    d.add(6 , 100);
    d.print();

    DynamicArray d1(d);   //Copy Constructor SHALLOW COPY
    d1.add(1 , 100);

    d.print();
    d1.print();

    DynamicArray d3;
    d3 = d;
    d3.add(90);
    d3.print();
    d.print();
    return 0;
}
