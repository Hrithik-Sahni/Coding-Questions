#include<math.h>
#include<bits/stdc++.h>
using namespace std;

void removeX(char arr[])
{
	if(arr[0] == '\0')
		return;

	removeX(arr + 1);
	
	if(arr[0] == 'x')
	{
		for(int i = 0; arr[i] != '\0' ; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
}

int main()
{
	char input[50];
	cin.getline(input , 50);

	removeX(input);

	cout << input << endl;

	return 0;
}