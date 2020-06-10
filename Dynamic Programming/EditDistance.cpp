#include<iostream>
#include<string>
using namespace std;

int lcs_DP(string s , string t){
    int m = s.size();
    int n = t.size();

    int**dp = new int*[s.size() + 1];
    for(int i = 0 ; i <= s.size() ; i++){
        dp[i] = new int[t.size() + 1];
    }

    for(int j = 0 ; j <= n ; j++){
        dp[0][j] = 0;
    }
    for(int i = 0 ; i <= m ; i++){
        dp[i][0] = 0;
    }
    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(s[m - i] == t[n - j]) // First Index is same so we will consider it
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                int a = dp[i - 1][j];
                int b = dp[i - 1][j - 1];
                inr c = dp[i][j - 1];
                dp[i][j] = max(a , max(b , c));
            }
        }
    }
    return dp[m][n];
}

int lcs_MEMO(string s , string t , int sSize , int tSize , int dp[][100]){
	if(s.size() == 0 || t.size() == 0)
		return 0;

	if(dp[sSize][tSize] != -1)
		return dp[sSize][tSize];

	if(s[0] == t[0])
	{
		int ans = lcs_MEMO(s.substr(1) , t.substr(1) , sSize - 1 , tSize - 1 , dp) + 1;
		dp[sSize][tSize] = ans;
		return ans;
	}

	int a = lcs_MEMO(s.substr(1) , t , sSize - 1 , tSize , dp);
	int b = lcs_MEMO(s , t.substr(1) , sSize , tSize - 1 , dp);
	int c = lcs_MEMO(s.substr(1) , t.substr(1) , sSize - 1 , tSize - 1 , dp);

	int final  = max(a , max(b , c));
	return dp[sSize][tSize] = final;
}

int main(){
	string s = "abcd";
	string t = "bacd";
	int dp[100][100];
	for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            dp[i][j] = -1;
	cout << lcs_MEMO(s , t , s.size() , t.size() , dp) << endl;
	cout << lcs_DP(s , t);
}
