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
		for(j=1; j<=(2*i)-1; j++)
		{
			if(j==i)
			{
				cout<<"0";
			}
			else if(j<i)
			{
				cout<<n-i+j;
			}
			else
			{
				cout<<n+i-j;
			}

		}
		cout<<endl;
	}

	return 0;
}



