#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int si, int li)
{
    int countSmall = 0 , temp,temp1,k = si;
    for(int i = si; i <= li; i++)
    {
        if(arr[i] < arr[si])
        {
          countSmall ++;
        }
    }

    temp = arr[si + countSmall];
    arr[si + countSmall] = arr[si];
    arr[si] = temp;

    int j = si + countSmall + 1;
    while(k < si + countSmall && j <= li )
    {
        if(arr[k] < arr[si + countSmall])
            k++;
        else if(arr[j] >= arr[si + countSmall])
            j++;
        else{
            temp1 = arr[j];
            arr[j] = arr[k];
            arr[k] = temp1;
            k++;
            j++;
        }

    }
    return (si + countSmall);

}
void quickSort(int arr[] , int si, int li)
{
    if(si >= li)
        return;

    int c = partition(arr, si, li);
    quickSort(arr, si, c - 1);
    quickSort(arr, c + 1, li);
}

int main()
{
    int arr[] = {10, 70, 80, 90, 100, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array using Quick Sort: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

