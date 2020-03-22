#include<iostream>
using namespace std;

int partition(int arr[], int si, int li)
{
    int countSmall = 0 , temp,temp1,k = si, j = li;
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
    
    while(k < si + countSmall && j > si + countSmall )
    {
        if(arr[k] < arr[si + countSmall])
            k++;
        else if(arr[j] >= arr[si + countSmall])
            j--;
        else{
            temp1 = arr[j];
            arr[j] = arr[k];
            arr[k] = temp1;
            k++;
            j--;
        }
        
    }
    return (si + countSmall);
        
}
void QuickSort(int arr[] , int si, int li)
{
    if(si >= li)
        return;
    
    int c = partition(arr, si, li);
    QuickSort(arr, si, c - 1);
    QuickSort(arr, c + 1, li);
}
void quickSort(int input[], int size) {

    int si = 0 , li = size - 1;
    QuickSort(input, si, li);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


