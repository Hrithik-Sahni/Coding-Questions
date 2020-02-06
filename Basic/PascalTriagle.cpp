#include<iostream>
using namespace std;

int fact(int n)
{
	int fact=1;
		for(int i=1; i<=n; i++)
			{
				fact=fact*i;
			}
		return fact;
	}

int main()
{
	int n;
	cout<<"Enter the number n : ";
	cin>>n;
	int a,b,c;
	for(int i=0; i<n; i++)
	{
		int k=1;
		while(k!=n-i)
		{
			cout<<" ";
			k++;
		}
		for(int j=0; j<=i; j++)
			{
				a=fact(i);
				b=fact(j)*fact(i-j);
				c=a/b;
				cout<<c<<" ";
			}
			cout<<endl;
	}
	return 0;
}
