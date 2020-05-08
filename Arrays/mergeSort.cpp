#include<iostream>
using namespace std;
void Merge(int* arr , int si , int mid , int en)
{
    int *temp = new int[en - si + 1];
    int i = si , j = mid + 1, k = si ;
    while(i <= mid && j <= en)
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    if(i > mid){
        while(j <= en){
                temp[k] = arr[j];
                k++;
                j++;
            }
    }
    else{
        while(i <= mid){
            temp[k] = arr[i];
            i++;
            k++;
        }
    }

    for(int i = si; i <= en; i++)
    {
        arr[i] = temp[i];
    }
}
void MergeSort(int* arr , int si , int en)
{
    if (si < en)
    {
        int mid = (si + en)/2;
        MergeSort(arr , si , mid);
        MergeSort(arr , mid + 1 , en);
        Merge(arr , si , mid , en);
    }
}

int main()
{
    int arr[] = {10,70,50,20,60,40,30};
    int siz = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr , 0 , siz - 1);
    cout << "Array after Merge Sort : ";
    for(auto data : arr){
        cout << data << " ";
    }
    cout << endl;
    return 0;
}
