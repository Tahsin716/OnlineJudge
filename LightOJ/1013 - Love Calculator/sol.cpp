#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

unsigned long long dp[31][31][31], subsequence[31][31];
string a, b;

unsigned long long lcs(int i, int j)
{
	if (i == a.size() || j == b.size()) return 0;

	if (subsequence[i][j] != -1) 
		return subsequence[i][j];

	unsigned long long ret = 0;

	if (a[i] == b[j])
	{
		ret = 1 + lcs(i + 1, j + 1);
	}
	else
	{
		ret = max(lcs(i + 1, j), lcs(i, j + 1));
	}

	return subsequence[i][j] = ret;
}

unsigned long long rec(int i, int j, int shortestSubsequenceString)
{
	if (i == a.size() and j == b.size() and !shortestSubsequenceString) return 1;

	if (i == a.size() and j == b.size() and shortestSubsequenceString) return 0;

	if (dp[i][j][shortestSubsequenceString] != -1)
		return dp[i][j][shortestSubsequenceString];

	if (i == a.size() and j != b.size())
		return dp[i][j][shortestSubsequenceString] = rec(i, j + 1, shortestSubsequenceString - 1);

	if (i != a.size() and j == b.size()) 
		return dp[i][j][shortestSubsequenceString] = rec(i + 1, j, shortestSubsequenceString - 1);

	if (a[i] == b[j])
		return dp[i][j][shortestSubsequenceString] = rec(i + 1, j + 1, shortestSubsequenceString - 1);

	dp[i][j][shortestSubsequenceString] = rec(i + 1, j, shortestSubsequenceString - 1) + rec(i, j + 1, shortestSubsequenceString - 1);

	return dp[i][j][shortestSubsequenceString];
}

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);

	while (T--)
	{
		cin >> a >> b;

		memset(dp, -1 , sizeof dp);
		memset(subsequence, -1, sizeof subsequence);

		int shortestSubsequenceString = a.size() + b.size() - lcs(0, 0); //Length of the shortest string that contains the subsequence

		printf("Case %d: %d %llu\n", ++testCase, shortestSubsequenceString, rec(0, 0, shortestSubsequenceString));
	}

	return 0;
}