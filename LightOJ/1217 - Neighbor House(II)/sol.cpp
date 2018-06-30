#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

int dp[1001][2], house[1001];
int n;

int rec(int index, bool first)
{
	if (index >= n) return 0;

	if (index == n - 1)
	{
		if (!first)
			return house[index];

		return 0;
	}

	if (dp[index][first] != -1)
		return dp[index][first];

	int ret = INT_MIN;

	//Take and increment by +2, since adjacent houses can't be taken
	// Or don't take and move to next house.
	// Check if index == 0 or not, that is, whether it is the first house you are taking
	if (index == 0)
	{
		ret = max(house[index] + rec(index + 2, 1), rec(index + 1, first)); 
	}
	else
	{
		ret = max(house[index] + rec(index + 2, first), rec(index + 1, first));
	}

	return dp[index][first] = ret;
}

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &house[i]);

		memset(dp, -1 ,sizeof dp);

		printf("Case %d: %d\n", ++testCase, rec(0, 0));
	}

	return 0;
}