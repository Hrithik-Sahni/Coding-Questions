#include<iostream>
using namespace std;

bool isprime(int n)
{
	if(n<=2)
	{
		return true;
	}
	for (int i=2; i<n; i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n1;
	cout<<"Enter the number "<<endl;
	cin>>n1;

	if(isprime(n1))
	{
		cout<<"Prime"<<endl;
	}
	else{
		cout<<"Not Prime"<<endl;
	}
	return 0;
}