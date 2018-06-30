#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int digit[70];
long long dp[70][70];

// bool first and temp taken, for WA due to unknown reasons
long long rec(int length, int left, int right, bool first, bool isLimit)
{
	if (left < right)
		return !isLimit || (isLimit && first);

	if (!isLimit && dp[length][left] != -1)
		return dp[length][left];

	int end = isLimit ? digit[left] : 9;

	long long ans = 0;

	for (int i = 0; i <= end; i++)
	{
		if (left == length - 1 && i == 0)
			continue;
		
		int temp = first;

		if (temp)
		{
			temp = digit[right] >= i;
		}
		else
		{
			temp = digit[right] > i;
		}

		ans += rec(length, left - 1, right + 1, temp, isLimit && i == end);
	}

	if (!isLimit)
		dp[length][left] = ans;

	return ans;
}


long long solve(long long n)
{
	int length = 0;

	if (n < 0) return 0; // 0 - 1 == -1

	if (n == 0) return 1;

	while (n)
	{
		digit[length++] = n % 10;
		n /= 10;
	}

	long long ans = 1; //Since n == 0 returns 1

	for (int i = length; i >= 1; i--)
		ans += rec(i, i - 1, 0, 1, i == length);

	return ans;
}

int main()
{
	int T, testCase = 0;
	long long i, j;

	memset(dp, -1 ,sizeof dp);

	scanf("%d", &T);

	while (T--)
	{
		cin >> i >> j;

		if (i > j)
			swap(i, j);

		printf("Case %d: %lld\n", ++testCase, solve(j) - solve(i - 1));
	}

	return 0;
}