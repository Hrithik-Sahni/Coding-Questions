#include<bits/stdc++.h>

using namespace std;

int main()
{
    static int num = 8;
	printf("%d" , num = num - 2);

	if(num)
	{
		main();
	}
}
