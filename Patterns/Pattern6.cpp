#include<iostream>
using namespace std;

int main()
{
	int i,j,n;
	cout<<"Number";
	cin>>n;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=i; j++)
		{
			cout<<"*";

		}
		cout<<endl;
	}
	for(int k=n-1; k>=1; k--)
	{
		for(int t=1; t<=k; t++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}
