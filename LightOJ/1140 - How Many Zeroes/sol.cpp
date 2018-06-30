#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int digit[26];
long long dp[26][26];

long long rec(int position, int count, int first, int isLimit)
{
	if (position == 0)
	{
		return first ? 1 : count;
	}
		

	if (!first && !isLimit && dp[position][count] != -1)
		return dp[position][count];

	int end = isLimit ? digit[position] : 9;

	long long ans = 0;

	for (int i = 0; i <= end; i++)
	{
		if (first)
		{
			ans += rec(position -1, count, first && i == 0, isLimit && i == end);
		}
		else
		{
			if (i == 0)
			{
				ans += rec(position - 1, count + 1, 0, isLimit && i == end);
			}
			else
			{
				ans += rec(position - 1, count, 0, isLimit && i == end);
			}
		}
	}

	if (!first && !isLimit)
		dp[position][count] = ans;

	return ans;
}

long long solve(long long n)
{
	int length = 0;

	if (n == 0)
		digit[++length] = 0;

	while (n)
	{
		digit[++length] = n % 10;
		n /= 10;
	}

	return rec(length, 0, 1, 1);
}

int main()
{
	int T, testCase = 0;
	long long m, n;

	scanf("%d", &T);

	while (T--)
	{
		memset(dp, -1, sizeof dp);

		scanf("%lld%lld", &m, &n);

		printf("Case %d: ", ++testCase);

		printf("%lld\n", solve(n) - solve(m - 1));
	}

	return 0;
}
