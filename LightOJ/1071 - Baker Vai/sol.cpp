#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[105][105][105], grid[105][105];
int m, n;

int rec(int r1, int c1, int r2, int c2)
{
	if (r1 >= m || c1 >= n || r2 >= m || c2 >= n) return 0;

	if (r1 == r2 && c1 == c2) return 0;

	if (dp[r1][c1][r2] != -1)
		return dp[r1][c1][r2];

	int ret = 0;

	ret = max(ret, rec(r1 + 1, c1, r2 + 1, c2));
	ret = max(ret, rec(r1 + 1, c1, r2, c2 + 1));
	ret = max(ret, rec(r1, c1 + 1, r2 + 1, c2));
	ret = max(ret, rec(r1, c1 + 1, r2, c2 + 1));

	return dp[r1][c1][r2] = ret + grid[r1][c1] + grid[r2][c2];
}

int main()
{
	int T, ans;

	scanf("%d", &T);

	for (int testCase = 1; testCase <= T; testCase++)
	{
		scanf("%d%d", &m, &n);

		for (int i = 0; i < m;  i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &grid[i][j]);

		memset(dp, -1, sizeof dp);

		ans = rec(0, 1, 1, 0) + grid[0][0] + grid[m - 1][n - 1];

		printf("Case %d: %d\n", testCase, ans);
	}

	return 0;
}