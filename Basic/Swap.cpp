#include<bits/stdc++.h>
using namespace std;

// void swap(int &x, int &y)  //CALL BY REFERENCE
// {
// 	int t;
// 	t=x;
// 	x=y;
// 	y=t;
// 	cout<<"Value in function: "<<"X: "<<x<<" Y: "<<y<<endl;
// }
int main()
{
	static int num = 8;
	printf("%d" , num = num - 2);

	if(num)
	{
		main();
	}

    // char *A[] = { "abcx", "dbba", "cccc"}; 
    // char var = *(A + 2) - *A;
    // cout << int(var);
    // cout << (*A + var); 
}

    