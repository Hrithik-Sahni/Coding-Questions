#include<iostream>

using namespace std;

void bubblesort(int input[] , int size)
{
	for(int i = 0 ; i < size; i++)
	{
		for( int j = 0; j < size - i; j++)
		{
			if(input[j] > input[j+1])
			{
				int temp;
				temp = input[j + 1];
				input[j + 1] = input[j];
				input[j] = temp;

			}
		}
	}
	for( int i = 0 ; i < size ; i ++)
		cout << input[i] << " ";
}
int main()

{
	int n;
	cin >> n;

	int * arr = new int[n];

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	bubblesort(arr , n);
	return 0;

}