#include<iostream>
using namespace std;

void swap(int &x, int &y)  //CALL BY REFERENCE
{
	int t;
	t=x;
	x=y;
	y=t;
	cout<<"Value in function: "<<"X: "<<x<<" Y: "<<y<<endl;
}
int main()
{
	int n,m;
	cin>>n>>m;
	swap(n,m);
	cout<<"Value after function is called: "<<"X: "<<n<<" Y: "<<m<<endl;
	return 0;
}