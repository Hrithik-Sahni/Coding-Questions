#include <iostream>
#include<vector>
using namespace std;
int kadanes(int arr[] , int n)
{
    int csum = arr[0];
    int global_max = arr[0];

    for(int i = 1; i < n ; i++)
    {
        if(csum < 0)
            csum = arr[i];
        else
            csum += arr[i];

        if(global_max < csum)
            global_max = csum;
    }
    return global_max;
}
int main()
{
    int arr[] = {10, 20 , -30 , -20 , 40 , 60 , -10};
    int n = 7;

    int maximumsubArray = kadanes(arr , n);
    cout << maximumsubArray;

    return 0;
}
