#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int bits[33];
long long dp[33][2][33];
int n;

long long rec(int postition, int previousBit, int count, int isLimit)
{
	if (postition <= 0) 
		return count;

	if (!isLimit && dp[postition][previousBit][count] != -1)
		return dp[postition][previousBit][count];

	int end = isLimit ? bits[postition] : 1;

	long long ans = 0;

	for (int i = 0; i <= end; i++)
	{
		if (previousBit == 1 && i == 1)
		{
			ans += rec(postition - 1, i, count + 1, isLimit && i == end);
		}
		else
		{
			ans += rec(postition - 1, i, count, isLimit && i == end);
		}
	}

	if (!isLimit)
		dp[postition][previousBit][count] = ans;

	return ans;
}

long long solve(int n)
{
	int length = 0;

	while (n)
	{
		bits[++length] = n % 2;
		n /= 2;
	}

	return rec(length, 0, 0, 1);
}

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);
	memset(dp, -1, sizeof dp);

	while(T--)
	{
		scanf("%d", &n);
		printf("Case %d: %lld\n", ++testCase, solve(n));
	}

	return 0;
}