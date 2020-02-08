#include<iostream>
using namespace std;
#define PI 3.14

int main()
{
	const int i = 11;
	int &j = i;
		cout << i << endl;
	j++;


	cout << i << endl;

	return 0;
}