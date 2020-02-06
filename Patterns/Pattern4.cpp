#include<iostream>
using namespace std;

int main()
{
	int i,j,n,ctr=1;
	cout<<"Number";
	cin>>n;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=i; j++)
		{
			cout<<ctr<<" ";
			ctr++;

		}
		cout<<endl;
	}
	return 0;
}
