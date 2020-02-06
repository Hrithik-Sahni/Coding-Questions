#include<iostream>
using namespace std;
int Binary(int arr[], int start, int end, int x)
{
    if(start > end)
        return -1;
    
    int mid = (start + end) / 2;
    
    if(arr[mid] == x)
        return mid;
    
    else if(arr[mid] > x)
        Binary(arr , start , mid - 1, x);
    
    else 
        Binary(arr, mid + 1, end, x);
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
    int start = 0 , end = size - 1;
    
    int ans = Binary(input, start, end, element);
    
    return ans;
}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
