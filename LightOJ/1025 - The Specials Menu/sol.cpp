#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string s;
long long dp[61][61];

long long rec(int left, int right)
{
	if (left == right) return 1;

	if (left > right) return 0;

	if (dp[left][right] != -1)
		return dp[left][right];

	long long ret = 0;

	if (s[left] == s[right])
		ret += rec(left + 1, right - 1) + 1;

	ret += rec(left + 1, right) + rec(left, right - 1) - rec(left + 1, right - 1);

	return dp[left][right] = ret;
}

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);

	while (T--)
	{
		cin >> s;

		int length = (int) s.size();

		memset(dp, -1, sizeof dp);

		printf("Case %d: %lld\n", ++testCase, rec(0, length -1));
	}

	return 0;
}