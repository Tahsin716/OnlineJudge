#include <bits/stdc++.h>

using namespace std;

int visited[505][505], ans[505*505];
char grid[505][505];
int M, N, Q;

//Quite similar to Guilty Prince problem
//run dfs on all possible directions
void dfs(int row, int column, int count)
{
	if (row < 0 or column < 0 or row >= N or column >= M or visited[row][column] or grid[row][column] == '#')
		return;

	visited[row][column] = count;
	ans[count] += grid[row][column] == 'C';

	dfs(row + 1, column, count);
	dfs(row - 1, column, count);
	dfs(row, column + 1, count);
	dfs(row, column - 1, count);
}

int main()
{
	int T, testCase = 0;
	int x, y;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d%d", &N, &M, &Q);

		for (int i = 0; i < N; i++)
			scanf("%s", grid[i]);

		memset(visited, 0, sizeof visited);
		memset(ans, 0, sizeof ans);


		//Run dfs from every possible co-ordinates
		//and store the count of how many crystals can be collected
		//from that co-ordinate
		for(int i = 0, count = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (grid[i][j] != '#' and !visited[i][j])
					dfs(i, j , ++count);
			}
		}

		printf("Case %d:\n", ++testCase);

		while (Q--)
		{
			scanf("%d%d", &x, &y);
			printf("%d\n", ans[ visited[x - 1][y - 1] ]);
		}
	}

	return 0;
}