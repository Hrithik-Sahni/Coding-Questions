#include<iostream>
using namespace std;

int main()
{
	int n;
	long long fact=1;
	cout<<"Enter the number"<<endl;
	cin>>n;

	for(int i=1; i<=n; i++)
	{
		fact=fact*i;
	}

	cout<<"The factorial of number "<<n<<" is "<<fact<<endl;

	return 0;
}
