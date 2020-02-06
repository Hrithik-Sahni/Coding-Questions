#include<iostream>
using namespace std;

int main()
{
	int n,a=0,b=1,c;

	cout<<"Enter the number"<<endl;
	cin>>n;

	cout<<a<<" ";
	
	for(int i=0; i<n; i++)
	{
		c=a+b;
		cout<<c<<" ";
		b=a;
		a=c;
	}


	return 0;

}