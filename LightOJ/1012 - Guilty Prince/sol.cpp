#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char grid[21][21];
int visited[21][21];
int height, width, count;

int dfs(int row, int column)
{
	if (row + 1 < height and !visited[row + 1][column] and grid[row + 1][column] == '.')
	{
		visited[row + 1][column] = 1;
		count++;

		dfs(row + 1, column);
	}

	if (row - 1 >= 0 and !visited[row - 1][column] and grid[row - 1][column] == '.')
	{
		visited[row - 1][column] = 1;
		count++;

		dfs(row - 1, column);
	}

	if (column + 1 < width and !visited[row][column + 1] and grid[row][column + 1] == '.')
	{
		visited[row][column + 1] = 1;
		count++;

		dfs(row, column + 1);
	}

	if (column - 1 >= 0 and !visited[row][column - 1] and grid[row][column - 1] == '.')
	{
		visited[row][column - 1] = 1;
		count++;

		dfs(row, column - 1);
	}
}


int main()
{
	int T, testCase = 0, startRow, startColumn;

	scanf("%d", &T);

	while (T--)
	{
		// scanf("%d%d", &width, &height);
		cin >> width >> height;
		count = 0;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				// scanf("%c", &grid[i][j]); it reads whitespace characters so answer will be wrong
				cin >> grid[i][j]; // use cin, since it ignores whitespace characters

				if (grid[i][j] == '@')
				{
					startRow = i;
					startColumn = j;
					count = 1;
				}
			}
		}


		memset(visited, 0, sizeof visited);
		visited[startRow][startColumn] = 1;

		dfs(startRow, startColumn);

		printf("Case %d: %d\n", ++testCase, count);
	}

	return 0;
}