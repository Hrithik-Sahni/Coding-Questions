#include<iostream>
#include <algorithm>
using namespace std;

// arr - input array
// size - size of array

int MissingNumber(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
//     int flag = 0;
//     for(int  i = 0; i < size; i ++)
//     {
//         flag = 0;
//         int element = arr[i];
//         for(int j = i + 1 ; j < size ; j ++)
//         {
//             if(element == arr[j])
//             {
//                 flag = 1;
//                 break;
        
//             }
//         }    
//         if(flag == 1)
//             return arr[i];
//     }
    
    int sum = 0;
    for(int i = 0; i < size; i ++)
    {
        sum += arr[i];
    }
    
    int sum2 = (size - 2) * (size - 1);
        sum2 = sum2/2;
    
    return sum - sum2;
    

}


int main() {
    int size;
    cin >> size;
    int *input = new int[1 + size];
    
    for(int i = 0; i < size; i++)
        cin >> input[i];
    
    cout << MissingNumber(input, size); 
    
    delete [] input;

    return 0;
}