#include<iostream>
#include <math.h>
using namespace std;

int main ()
{
	int n,ctr=0;
	cout<<"Enter the number"<<endl;
	cin>>n;

	if(n==2)
		cout<<"It is a Prime Number";
	else
	{

		for(int i=2; i<int (sqrt(n)); i++)
		{
			if(n%i==0)
			{
				ctr=1;
				break;
			}
		}
		if(ctr==0)
			cout<<"It is a Prime Number";
		else
			cout<<"It is not a Prime Number";
	}

	return 0;
}
