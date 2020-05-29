#include<iostream>
using namespace std;

int fibbo_memo(int n , int dp[])
{
	if(n == 0 || n == 1)
		return n;

	if(dp[n] != -1)
		return dp[n];

	int a = fibbo_memo(n - 1 , dp);
	int b = fibbo_memo(n - 2 , dp);

	return dp[n] = a + b;
}

int fibbo_BU(int n )
{
 	int dp[100];
	for(int i = 0 ; i < 100; i ++)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(){
	int dp[100];
	for(int i = 0 ; i < 100; i ++)
    {
        dp[i] = -1;
    }
	cout << fibbo_memo(10 , dp) << endl;
	cout << fibbo_BU(10);

	return 0;
}
