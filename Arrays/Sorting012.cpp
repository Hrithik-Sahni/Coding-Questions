#include<iostream>
using namespace std;

void sort(int arr[100], int n)
{
	int l=0,h=n-1,itr=1;
	while(itr<=h)
	{
		if(arr[itr]==0)
		{
			int temp=arr[l];
			arr[l]=arr[itr];
			arr[itr]=temp;
			l++;
			itr++;
		}
		else if(arr[itr]==1)
		{
			itr++;
		}
		else
		{
			int temp=arr[h];
			arr[h]=arr[itr];
			arr[itr]=temp;
			itr++;
			h--;

		}
	}
}


int main()
{
	int arr[]={0,1,2,0,1,2,0};
	int size=sizeof(arr)/sizeof(int);
	sort(arr,size);

	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
