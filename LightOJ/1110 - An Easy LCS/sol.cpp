#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[101][101];
string firstString, secondString, lcs[101][101];


string rec(int i, int j)
{
	if (i == firstString.size() || j == secondString.size()) return "";

	if (dp[i][j] != -1)
		return lcs[i][j];

	dp[i][j] = 1;

	if (firstString[i] == secondString[j])
	{
		lcs[i][j] = firstString[i] + rec(i + 1, j + 1); //We can use either firstString[i] or secondString[j], since both are equal.
	}
	else
	{
		string ret1 = rec(i + 1, j);
		string ret2 = rec(i, j + 1);

		//Choose the longest common subsequence, but if both are equal in size
		//in that case, choose the one which is smallest in lexicographical order

		if (ret1.size() > ret2.size())
		{
			lcs[i][j] = ret1;
		}
		else if (ret1.size() < ret2.size())
		{
			lcs[i][j] = ret2;
		}
		else
		{
			lcs[i][j] = min(ret1, ret2); //Lexicographically smallest, LCS
		}
	}

	return lcs[i][j];
}

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);

	while (T--)
	{
		cin >> firstString >> secondString;

		memset(dp, -1, sizeof dp);

		printf("Case %d: %s\n", ++testCase, (rec(0, 0).size() == 0)? ":(" : lcs[0][0].c_str()); 
	}

	 // string ans = (ternary_condition) does not work
	 // We need to do this
	 //
	 //bool a;
	 //
	 // string s;
	 // s.append(string("a:") + (a? "true" : "false"));

	return 0;
}	