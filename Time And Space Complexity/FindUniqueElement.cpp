#include<iostream>
using namespace std;

int FindUnique(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int flag = 0;
    for(int  i = 0; i < size; i ++)
    {
        flag = 0;
        int element = arr[i];
        for(int j = i + 1 ; j < size ; j ++)
        {
            if(element == arr[j])
            {
                flag = 1;
                break;
        
            }
        }    
        if(flag == 0 )
            return arr[i];
    }
}

int main() {

    int size;

    cin>>size;
    int *input=new int[1+size]; 
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    
    cout<<FindUnique(input,size)<<endl;
        
    return 0;
}
