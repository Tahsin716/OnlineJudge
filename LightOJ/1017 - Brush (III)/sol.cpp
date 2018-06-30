#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int points[101], dp[101][101];
int n, brushWidth, moves;

int rec(int position, int remainingMoves)
{
	if (position >= n || remainingMoves == 0)
	{
		return 0;
	}

	if (dp[position][remainingMoves] != -1)
		return dp[position][remainingMoves];

	int ret = -1;
	int brushCoverage = points[position] + brushWidth;
	
	int taken = 0, index;

	for (index = position; index < n && points[index] <= brushCoverage; index++)
	{
		taken++;
	}

	taken += rec(index, remainingMoves - 1);

	int not_taken = rec(position + 1, remainingMoves);

	ret = max(taken, not_taken);

	return dp[position][remainingMoves] = ret;
}

int main()
{
	int T, testCase = 0;
	int x, y;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d%d", &n, &brushWidth, &moves);
		memset(dp, -1, sizeof dp);

		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			points[i] = y;
		}

		sort(points, points + n);

		printf("Case %d: %d\n", ++testCase, rec(0, moves));
	}

	return 0;
}