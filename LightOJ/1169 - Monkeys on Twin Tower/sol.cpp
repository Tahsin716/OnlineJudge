#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[1001][2];
int towerLeft[1001], towerRight[1001], jumpTimeLeft[1001], jumpTimeRight[1001];
int n;

int rec(int position, int tower)
{
	if (position >= n) return 0;

	if (dp[position][tower] != -1)
		return dp[position][tower];

	if (tower == 0)
	{
		return dp[position][tower] = towerLeft[position] + min(rec(position + 1, 0), jumpTimeLeft[position] + rec(position + 1, 1));
	}
	else
	{
		return dp[position][tower] = towerRight[position] + min(rec(position + 1, 1), jumpTimeRight[position] + rec(position + 1, 0));
	}
}

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		memset(dp, -1, sizeof dp);

		for (int i = 0; i < n; i++)
			scanf("%d", &towerLeft[i]);

		for (int i = 0; i < n; i++)
			scanf("%d", &towerRight[i]);

		for (int i = 0; i < n - 1; i++)
			scanf("%d", &jumpTimeLeft[i]);

		for (int i = 0; i < n - 1; i++)
			scanf("%d", &jumpTimeRight[i]);

		printf("Case %d: %d\n", ++testCase, min(rec(0, 0), rec(0, 1)));
	}

	return 0;
}