#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    
    // vector<int> *v = new vector<int>(); Dynamic Allocation

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;

    v.at(2);      // Element at 2nd position.
    v.size()      // Size of the vector.
    v.capacity()  // capacity of the vector which is the size of the internal array.

}