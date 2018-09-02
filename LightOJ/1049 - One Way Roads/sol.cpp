#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int N = 105;

vector<int>Graph[N];
int cost[N][N];
bool checked[N];
int redirectionCost;

void dfs(int source, int destination)
{
	bool ok = false; //To check whether this node need redirection or not

	// If this node has already been checked
	if (checked[source] == true)
		return;

	checked[source] = true;

	for (int i = 0; i < Graph[source].size(); i++)
	{
		int v = Graph[source][i]; //Adjacent node

		if (checked[v] == false)
		{
			redirectionCost += cost[source][v];
			dfs(v, destination);
			ok = true;
		}
	}

	if (ok == false)
	{
		redirectionCost += cost[source][destination];
	}
}

int main()
{
	int T, testCase = 0, n, a, b, c;
	int totalCost;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		memset(cost, 0, sizeof cost);
		memset(checked, false, sizeof checked);

		for (int i = 0; i < N; i++)
			Graph[i].clear();

		totalCost = 0;
		redirectionCost = 0;

		// 1 <= a, b <= n; a =/= b
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a, &b, &c);

			Graph[a].push_back(b);
			Graph[b].push_back(a);

			cost[a][b] = 0;
			cost[b][a] = c; //Redirecting cost

			totalCost += c; //Total cost for redirection
		}

		dfs(1, 1);

		printf("Case %d: %d\n", ++testCase, min(redirectionCost, totalCost - redirectionCost));

	}

	return 0;
}