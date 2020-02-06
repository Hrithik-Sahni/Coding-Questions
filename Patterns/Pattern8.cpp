#include<iostream>
using namespace std;

int main()
{
	int i,j,n;
	cout<<"Number";
	cin>>n;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<n+i; j++)
		{
			if(j<=n-i)
			{
				cout<<" ";
			}
			else
			{
				cout<<"*";
			}
		}
		cout<<endl;
	}
	for(int k=n-1,s=0; k>=1; k--,s=0)
	{
		for(int t=1; t<=n-k; t++)
		{
			cout<<" ";
		}
		while(s!=(2*k)-1)
		{
			cout<<"*";
			s++;
		}
		cout<<endl;
	}

	return 0;
}
