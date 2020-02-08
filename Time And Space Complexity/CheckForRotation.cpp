#include<iostream>
#include <algorithm>
using namespace std;

#include<algorithm>
int FindSortedArrayRotation(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int min = arr[0];
    int pos = 0;

    for(int i = 0 ; i < n; i ++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            pos = i;
        }
    }
    return pos;
}

int main() {

    int size;
    cin>>size;
    int *input=new int[1+size]; 
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    
    cout<<FindSortedArrayRotation(input,size);
    
    return 0;

}
