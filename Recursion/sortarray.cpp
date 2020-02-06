#include<iostream>
using namespace std;

int sorting(int a[], int size)
{
	if(size == 0 || size == 1)
		return true;

	if(a[0]>a[1]){
		return false;
	}
	
	bool isSmaller=sorting(a+1, size-1);
	return isSmaller;
}

int main()
{
	/* code */
	int n;
	cout << "Enter the number : " << endl;
	cin >> n;
	cout << fibonacci(n) << endl;
	return 0;
}