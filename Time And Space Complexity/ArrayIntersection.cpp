#include<iostream>
#include <algorithm>
using namespace std;

// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array

void intersection(int input1[], int input2[], int size1, int size2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
  sort(input1 , input1 + size1);
  sort(input2 , input2 + size2);
  int i = 0, j = 0; 
  while (i < size1 && j < size2) 
  { 
    if (input1[i] < input2[j]) 
       i++; 
    else if (input2[j] < input1[i]) 
       j++; 
    else /* if arr1[i] == arr2[j] */
    { 
       cout << input2[j] << endl; 
       i++; 
       j++; 
    } 
  } 
} 


int main() {

    int size1,size2;

    cin>>size1;
    int *input1=new int[1+size1];   
    
    for(int i=0;i<size1;i++)
        cin>>input1[i];

    cin>>size2;
    int *input2=new int[1+size2];   
    
    for(int i=0;i<size2;i++)
        cin>>input2[i];
    
    
    intersection(input1,input2,size1,size2);

        
    return 0;
}