#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int fun(int a , int b){
    if (b<=0) return 0;
    else return a+fun(a,b-1);
}
int main()
{
    int[] arr = new int[4];
    arr[0] = 12;
    for(auto i : arr)
        cout << arr[i];
}
