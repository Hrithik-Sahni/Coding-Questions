#include<iostream>
using namespace std;

void printsubsetK(int input[] , int n , int k , int output[] , int m)
{
    int NewOutput[10000];
    if(n == 0)
    {
        if( k == 0)
        {
            for(int i = 0; i < m ; i++)
                cout << output[i] << " ";
            cout << endl;
        }
        return;
    }
    
    printsubsetK(input + 1, n - 1 , k , output , m);
    
    for(int i = 0; i < m; i ++)
    {
        NewOutput[i] = output[i];
    }
    NewOutput[m] = input[0];
    printsubsetK(input + 1, n - 1, k - input[0], NewOutput, m + 1);
        
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[10000];
    printsubsetK(input , size , k , output , 0);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
