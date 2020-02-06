#include<iostream>
using namespace std;

int main()
{
	int a=1,d=2,n,sum=0,an;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		an= a + (i-1)*d;
		cout<<"Term "<<i<<" "<<an<<endl;
		sum=sum+an;
	}
	cout<<endl;
	cout<<"Sum is "<<sum<<endl;
	return 0;
}
