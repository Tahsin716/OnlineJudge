#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int dp[11][11], num[11];
int n, m;

int rec(int startingNumber, int totalDigit)
{
	if (totalDigit == 1) return 1;

	if (dp[startingNumber][totalDigit] != -1)
		return dp[startingNumber][totalDigit];

	int ret = 0;

	//For consecutive numbers, after the starting number
	//Then send the consecutive number as, startingNumber and recursively check
	//Whether difference is less than or equal to 2.
	for (int i = 0; i < m; i++)
	{
		if ( abs(num[startingNumber] - num[i]) <= 2)
		{
			ret += rec(i, totalDigit - 1);
		}
	}

	return dp[startingNumber][totalDigit] = ret;
}


int main()
{
	int T, testCase = 0;
	long long ans;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d", &m, &n);

		for (int i = 0; i < m; i++)
			scanf("%d", &num[i]);

		ans = 0;

		memset(dp, -1, sizeof dp);

		//Loop through each starting number
		for (int i = 0; i < m; i++)
			ans += rec(i, n);

		printf("Case %d: %lld\n", ++testCase, ans);
	}

	return 0;
}