#include<iostream>
using namespace std;

int main()
{
	int i = 65; 
	char c = i;

	int *p = &i;
	char *pc = (char*)p;

	cout << p << endl;
	cout << pc << endl;
 	
	return 0;
}