#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>


using namespace std;

int n;
int dp[1005][1005];
int a[25][5];

int rec(int index, int color)
{
	if (index > n)
		return 0;

	if (dp[index][color] != -1)
		return dp[index][color];

	int neigbour_color_1, neigbour_color_2, min_cost_1, min_cost_2;

	if (color == 1)
	{
		neigbour_color_1 = 2;
		neigbour_color_2 = 3;
	}
	else if (color == 2)
	{
		neigbour_color_1 = 1;
		neigbour_color_2 = 3;
	}
	else
	{
		neigbour_color_1 = 1;
		neigbour_color_2 = 2;
	}

	min_cost_1 = a[index][color] + rec(index + 1, neigbour_color_1);
	min_cost_2 = a[index][color] + rec(index + 1, neigbour_color_2);

	dp[index][color] = min(min_cost_1, min_cost_2);

	return dp[index][color];
}

int main()
{
    #ifdef SAMPLE_TEST
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // SAMPLE_TEST

	int T;
	scanf("%d", &T);

	for (int testCase = 1; testCase <= T; testCase++)
	{

		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}

		int ans = INT_MAX;

		for (int i = 1; i <= 3; i++)
		{
			ans = min(ans, rec(1, i));
		}

		printf("Case %d: %d\n", testCase, ans);
	}

    return 0;
}
