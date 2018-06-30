#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n , W, count;
int itemWeight[101], itemPrice[101];
int dp[101][10001];

int rec(int index, int weight)
{
	int takeAndIncrement = 0;
	int takeAndStay = 0;
	int dontTake = 0;

	if (index >= n) return 0;

	if (dp[index][weight] != -1)
		return dp[index][weight];

	if (weight + itemWeight[index] <= W)
	{
		takeAndIncrement = rec(index + 1, weight + itemWeight[index]) + itemPrice[index];

		takeAndStay = rec(index, weight + itemWeight[index]) + itemPrice[index];
	}

	dontTake = rec(index + 1, weight);

	return dp[index][weight] = max(dontTake, max(takeAndIncrement, takeAndStay));
}

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d", &n, &W);

		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &itemPrice[i], &count, &itemWeight[i]);

			W = W - itemWeight[i] * count;
		}

		if (W < 0)
		{
			printf("Case %d: Impossible\n", ++testCase);
			continue;
		}

		memset(dp, -1, sizeof dp);

		printf("Case %d: %d\n", ++testCase, rec(0, 0));
	}

	return 0;
}