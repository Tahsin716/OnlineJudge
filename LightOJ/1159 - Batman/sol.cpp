#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[51][51][51], firstLength, secondLength, thirdLength;
string firstString, secondString, thirdString;

int rec(int i, int j, int k)
{
	if (i == firstLength || j == secondLength || k == thirdLength) return 0;

	if (dp[i][j][k] != -1)
		return dp[i][j][k];

	int ret = 0;

	if (firstString[i] == secondString[j] and secondString[j] == thirdString[k])
	{
		ret = 1 + rec(i + 1, j + 1, k + 1);
	}
	else
	{
		ret = max(max(rec(i + 1, j, k), rec(i, j + 1, k)), rec(i , j, k + 1));
	}

	return dp[i][j][k] = ret;
}

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);

	while (T--)
	{
		cin >> firstString >> secondString >> thirdString;

		firstLength = firstString.size();
		secondLength = secondString.size();
		thirdLength = thirdString.size();

		memset(dp, -1, sizeof dp);

		printf("Case %d: %d\n", ++testCase, rec(0, 0, 0));
	}

	return 0;
}