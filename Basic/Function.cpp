#include<iostream>
#include<math.h>
using namespace std;

int powe(int a, int number)
{
	int c;
	c=pow(number,a);
	return c;
}

int main()
{
	int num,power;
	cout<<"Enter the number"<<endl; 
	cin>>num;
	cout<<"Enter the power"<<endl;
	cin>>power;
	cout<<"Answer is "<<powe(power,num);

	return 0;
}



