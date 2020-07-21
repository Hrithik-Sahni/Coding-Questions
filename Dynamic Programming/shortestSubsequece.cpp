#include <iostream>
#include <string>
using namespace std;

int shortestSubsequence_memo(string a , string b , int siA , int siB , int dp[a.length()][b.length()])
{
	if(siB == b.length())
		return 1; // String B is empty shorstest subsequence in A which is not a part of B is 1 (any character)
	if(siA == a.length())
		return 1001; // Any maximum number as the first string is empty so no subsequence of A is possible which is a part of A and not B

	if(dp[siA][siB] != -1)
		return dp[siA][siB];

	// if a[0] is not included
	int ans1 =  shortestSubsequence(a , b , siA + 1 , siB , dp);

	// if a[0] is included
	//the we need to search for a[0] in string b if found at index x then siB = x + 1 and siA = siA + 1 
	int index = -1;
	for(int i = siB ; i < b.length(); i ++)
	{
		if(b[i] == a[siA])
		{
			index = i;
			break;
		}
	}
	if(index == -1)
		return 1; // a[0] is the shortest subsequence
	int ans2 = 1 + shortestSubsequence(a , b , siA + 1 , index + 1 , dp); //a[0] is also included in the length
	int final_ans = 0
	if(ans1 < ans2)
		final_ans = ans1;
	else 
		final_ans = ans2;
	dp[siA][siB] = ans;
	return ans;
}

//Number of unique calls will be sizeof a * sizeof b . Rest all will be repition
// DP array storing from which start index to which start index so 0----a.size() - 1
int shortestSubsequence(string a , string b )
{
	int dp[a.length()][b.length()];
	for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            dp[i][j] = -1;
        }
    }
	shortestSubsequence_memo(a , b , 0 , 0 , dp)
}