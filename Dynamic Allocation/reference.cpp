#include <iostream>

using namespace std;

void increment(int &n){
	n++;
}

int main()
{
	/* code */

	int i;
	i = 10;
	int &j = i;   // j is the refernce variable of i

	increment(i);

	cout << j++ << " " << i << endl;


	return 0;
}