#include<iostream>
using namespace std;

int main()
{	
	int i,j,k,n;
	cout<<"Number";
	cin>>n;

	for(i=0; i<n; i++)
	{
		int k=0;
		while(k!=2*i)
		{
			cout<<" ";
			k++;
		}
		for(j=1; j<=n-i; j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}

	return 0;
}



