#include<iostream>
using namespace std;

int main()
{	
	int i,j,k,n;
	cout<<"Number";
	cin>>n;

	for(i=1; i<=n; i++)
	{
		int k=0;
		while(k!=n-i)
		{
			cout<<" ";
			k++;
		}
		for(j=1; j<=i; j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	for(i=n-1; i>=1; i--)
	{
		int k=n;
		while(k!=i)
		{
			cout<<" ";
			k--;
		}
		for(j=1; j<=i; j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}


	return 0;
}



