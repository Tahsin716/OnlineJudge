#include <iostream>
#include <cstdio>
#include <cstring>

int dp[15][110][110], digit[15];
int A, B, K;

int rec(int position, int number, int sum, int isLimit)
{
	if (position == 0)
	{
		return number == 0 && sum == 0;
	}

	if (!isLimit && dp[position][number][sum] != -1)
		return dp[position][number][sum];

	int ans = 0;

	int end = isLimit ? digit[position] : 9;

	for (int i = 0; i <= end; i++)
	{
		ans += rec(position - 1, (number*10 + i) % K, (sum + i) % K, isLimit && i == end);
	}

	if (!isLimit)
		dp[position][number][sum] = ans;

	return ans;
}

int solve(int n)
{
	int length = 0;

	memset(dp, -1, sizeof dp);

	while (n)
	{
		digit[++length] = n % 10;
		n /= 10;
	}

	return rec(length, 0, 0, 1);
}

int main()
{
	int T, testCase = 0, ans;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d%d", &A, &B, &K);

		printf("Case %d: ", ++testCase);
		
		ans = 0;

		if (K <= 90)
		{
			ans = solve(B) - solve(A - 1);
		}
		
		printf("%d\n", ans);
	}

	return 0;
}