#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 20005;

vector<int>Graph[N];
int color[N];

enum {NOT_VISITED, BLACK, RED};


//Vampires and Lykans are denoted by two different colors - BLACK and RED
//At first all nodes are unassigned, then select a node and make it either black or red
//Run a bfs and make every node adjacent to a black node, as red node.
//And every node adjacent to a red node, as black node.

int bfs(int source)
{
	queue<int> q;
	int black = 0, red = 0;

	q.push(source);

	color[source] = BLACK;
	black++;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int i = 0; i < Graph[u].size(); i++)
		{
			int v = Graph[u][i]; //Adjacent node

			if (color[v] == NOT_VISITED)
			{
				q.push(v);

				//If the node is black, then make the adjacent nodes red
				if (color[u] == BLACK)
				{
					color[v] = RED;
					red++;
				}
				//Else if the node is red, then make the adjacent nodes black
				else
				{
					color[v] = BLACK;
					black++;
				}
			}
		}
	}

	return max(black, red); //Take the maximum between black and red nodes
}

int main()
{
	int T, testCase = 0, n, u, v;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		for (int i = 0; i < N; i++)
			Graph[i].clear();

		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &u, &v);

			Graph[u].push_back(v);
			Graph[v].push_back(u);
		}

		int ans = 0;

		memset(color, 0, sizeof color);

		//We cannot assume that the graph is connected
		//Example: 1 5
		//		   5 10
		//         8 20

		for (int i = 0; i < N; i++)
		{
			if (color[i] == NOT_VISITED and !Graph[i].empty())
			{
				ans += bfs(i);
			}
		}

		printf("Case %d: %d\n", ++testCase, ans);
	}

	return 0;
}