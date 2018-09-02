#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

vector <pair <int, int> > Graph[30005];

bool visited[30005];
int maximum, start;

int dfs(int source, int distance)
{
	visited[source] = 1;

	int v, weight;

	if (distance > maximum)
	{
		maximum = distance;
		start = source;
	}

	for (int i = 0; i < Graph[source].size(); i++)
	{
		v = Graph[source][i].first; //Adjacent node
		weight = Graph[source][i].second; //Weight of the edge, of the adjacent node

		//If the adjacent node has not been visited
		if (!visited[v])
		{
			dfs(v, distance + weight);
		}
	}
}

int main()
{
	int T, testCase = 0, x, y, w, n, temp;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			Graph[i].clear();

		for (int i = 0; i < n - 1; i++)
		{
			scanf("%d%d%d", &x, &y, &w);

			Graph[x].push_back(make_pair(y, w));
			Graph[y].push_back(make_pair(x, w));
		}

		maximum = INT_MIN;
		memset(visited, 0, sizeof visited);

		dfs(0, 0);
		temp = start;

		maximum = INT_MIN;
		memset(visited, 0, sizeof visited);
		
		dfs(start, 0);

		printf("Case %d: %d\n", ++testCase, maximum);		
	}

	return 0;
}