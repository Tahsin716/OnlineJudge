#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int dp[ (1 << 10) + 1][1001], freq[11], factorial[11];
char s[11];
int n, d;

int Set(int mask, int pos)
{
	return mask = mask | (1 << pos);
}

bool check(int mask, int pos)
{
	return (bool) (mask & (1 << pos));
}

int rec(int position, int mask, int remainder)
{
	if (position == n)
	{
		return remainder == 0;
	}

	if (dp[mask][remainder] != -1)
		return dp[mask][remainder];

	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		if (check(mask, i) == 0)
		{
			ret += rec(position + 1, Set(mask, i), (remainder * 10 + s[i] - '0') % d);
		}
	}

	return dp[mask][remainder] = ret;
}

int main()
{
	int T, testCase = 0, ans;

	scanf("%d", &T);

	factorial[0] = 1;

	for (int i = 1; i < 12; i++)
		factorial[i] = factorial[i - 1] * i;

	while (T--)
	{
		scanf("%s%d", s, &d);

		n = strlen(s);

		memset(dp, -1, sizeof dp);
		memset(freq, 0, sizeof freq);

		for (int i = 0; i < n; i++)
		{
			freq[s[i] - '0']++;
		}

		ans = rec(0, 0, 0);

		for (int i = 0; i < 10; i++)
		{
			ans = ans / factorial[freq[i]];
		}

		printf("Case %d: %d\n", ++testCase, ans);
	}

	return 0;
}