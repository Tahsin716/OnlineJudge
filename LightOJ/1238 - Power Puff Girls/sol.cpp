#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>

using namespace std;

char grid[21][21];
int visited[21][21], positionRow[3], positionColumn[3];
int height, width, count;

// For, row + 1, row -1 , column + 1 and column - 1
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node
{
	int x, y;
	int step;
};

bool notVaild(int row, int column)
{
	if (row < 0 or column < 0 or row > height or column > width)
		return true;

	if (visited[row][column] or grid[row][column] == '#' or grid[row][column] == 'm')
		return true;

	return false;
}


int bfs(Node node)
{
	visited[node.x][node.y] = 1;
	
	queue<Node> q;
	q.push(node);

	while (!q.empty())
	{
		Node top = q.front();
		q.pop();

		if (grid[top.x][top.y] == 'h')
			return top.step;

		// Four direction, thus loop upto 4
		for (int i = 0; i < 4; i++)
		{
			Node temp; // New node which will go in the following directions, East, West, North, South

			temp.x = dx[i] + top.x;
			temp.y = dy[i] + top.y;

			if (notVaild(temp.x, temp.y))
				continue;

			visited[temp.x][temp.y] = 1;
			temp.step = top.step + 1; // Previous step counts and current step, so +1

			q.push(temp); // Insert the new node in the queue
		}
	}

	return 0; // We can always reach 'h', so this statement isn't really necessary
}


int main()
{
	int T, testCase = 0, x, y;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d", &height, &width);

		x = 0; y = 0;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cin >> grid[i][j];

				if (grid[i][j] == 'a' or grid[i][j] == 'b' or grid[i][j] == 'c')
				{
					positionRow[y++] = i;
					positionColumn[x++] = j;
				}
			}
		}

		int ans = INT_MIN;

		for (int i = 0; i < 3; i++)
		{
			memset(visited, 0, sizeof visited);
			
			Node temp;

			temp.x = positionRow[i];
			temp.y = positionColumn[i];
			temp.step = 0;

			ans = max(ans, bfs(temp));
		}

		printf("Case %d: %d\n", ++testCase, ans);
	}

	return 0;
}