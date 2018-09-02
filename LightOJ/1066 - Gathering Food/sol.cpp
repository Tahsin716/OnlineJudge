#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node
{
	int x;
	int y;
	int step;
};

int n, k;

int visited[20][20];
char grid[20][20];

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

bool notValid(int row, int column)
{
	if (row < 0 or column < 0 or row > n or column > n)
		return true;

	if (visited[row][column] or grid[row][column] == '#')
		return true;
	
	return false;
}

Node bfs(char target, Node node)
{	
	queue<Node> q;
	q.push(node);

	visited[node.x][node.y] = 1;

	int topX, topY, tempX, tempY;

	while (!q.empty())
	{
		Node top = q.front();
		q.pop();

		topX = top.x;
		topY = top.y;

		//Target food found so return the node, where it has been found
		if (grid[topX][topY] == target)
			return top;

		//Four directions, thus loop upto 4
		for (int i = 0; i < 4; i++)
		{
			if ((topX + dx[i] < n and topX + dx[i] >= 0) and (topY + dy[i] < n and topY + dy[i] >= 0))
			{

				Node temp; // New node which will go in the following directions, East, West, North, South

				tempX = topX + dx[i];
				tempY = topY + dy[i];

				//We can only pick the target, or move along empty space, we can't pick 
				//alphabetically larger food, than target
				if ((grid[tempX][tempY] == '.' or grid[tempX][tempY] == target) and visited[tempX][tempY] == 0)
				{
					temp.x = topX + dx[i];
					temp.y = topY + dy[i];

					temp.step = top.step + 1;
					visited[tempX][tempY] = 1;

					q.push(temp);
				}

			}
		}
	}

	//In case it is not possible to reach the target
	Node temp;
	temp.step = INT_MAX;
	
	return temp;
}


int main()
{
	int T, testCase = 0;
	int sum, startX, startY, temp;
	char target;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);
		
		k = INT_MIN;
		sum = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> grid[i][j];

				temp = grid[i][j] - 'A' + 1;
				k = max(k, temp); //Which is the max alphabet

				if (grid[i][j] == 'A')
				{
					startX = i;
					startY = j;
				}
			}
		}

		Node temp;

		temp.x = startX;
		temp.y = startY;
		

		int i = 0; //For checking whether all the foods have been taken

		for (i = 0; i < k; i++)
		{
			target = 'A' + i;
			temp.step = 0;

			memset(visited, 0, sizeof visited);
			
			temp = bfs(target, temp);

			//Not able to reach the target
			if (temp.step == INT_MAX)
				break;

			grid[temp.x][temp.y] = '.'; //Collected the target food, so making this cell empty now

			sum += temp.step; //Total steps
		}

		//Check wheter all the food has been collected or not
		if (i == k)
		{
			printf("Case %d: %d\n", ++testCase, sum);
		}
		else
		{
			printf("Case %d: Impossible\n", ++testCase);
		}
	}

	return 0;
}