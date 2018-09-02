#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>

using namespace std;

vector<int> Graph[1009];
int count[1009], visited[1009], a[101], N, M, K, ans;

void bfs(int source)
{
	visited[source] = 1;

	queue<int> q;
	q.push(source);

	count[source]++; //We are keeping count of how many people can reach this city

	//If the number of people who can reach this city == K(total no. of people); then ans++
	if (count[source] == K)
		ans++;

	while (!q.empty())
	{
		int top = q.front();
		q.pop();

		for (int i = 0; i < Graph[top].size(); i++)
		{
			int v = Graph[top][i]; // Adjacent node

			// Adjacent node has not been visited
			if (!visited[v])
			{
				visited[v] = 1;
				count[v]++;

				//If the number of people who can reach this city == K(total no. of people); then ans++
				if (count[v] == K)
					ans++;

				q.push(v);
			}
		}
	}
}


int main()
{
	int T, testCase = 0, u, v;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d%d", &K, &N, &M);

		for (int i = 0; i <= N; i++)
			Graph[i].clear();

		for (int i = 0; i < K; i++)
			scanf("%d", &a[i]);

		for (int i = 0; i < M; i++)
		{
			scanf("%d%d", &u, &v);

			Graph[u].push_back(v); // One way road
		}

		memset(count, 0, sizeof count);
		ans = 0;

		//BFS from the location of all people, to check how many cities can be reached by all people(K)
		for (int i = 0; i < K; i++)
		{
			memset(visited, 0, sizeof visited);

			bfs(a[i]);
		}

		printf("Case %d: %d\n", ++testCase, ans);
	}

	return 0;
}