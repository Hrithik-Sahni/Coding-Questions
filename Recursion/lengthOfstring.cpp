#include<math.h>
#include<bits/stdc++.h>
using namespace std;

int getlength(char arr[])
{
	if(arr[0] == '\0')
		return 0;

	int ans = getlength(arr + 1);
	return ans + 1;
}

int main()
{
	char input[50];
	cin.getline(input , 50);

	cout << getlength(input) << endl;

	return 0;
}