#include <bits/stdc++.h>

using namespace std;

int a[105][105];
const int INF = 1 << 20;

int main()
{
	int T, testCase = 0, N, R, u, v, s, d, ans;

	scanf("%d", &T);

	while (T--)
	{
		//N == no. of buildings in the headquarter
		//R == no. of roads connecting the buildings
		scanf("%d%d", &N, &R); 

		//All Pair Shortest Path Problem
		//First we will initialize the array with all, indices as INF
		//Except self-loop, which shall be Zero.
		//We will use Floyd Warshall Algorithm for this problem
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				a[i][j] = INF; //All indices will be INF, using INT_MAX causes overflow here
			}

			a[i][i] = 0; //Self-loop shall be 0, since it will take 0 time to reach itself
		}

		//There is one road to go between u and v
		//The cost to go through this road is 1.
		for (int i = 0; i < R; i++)
		{
			scanf("%d%d", &u, &v);

			a[u][v] = 1;
			a[v][u] = 1;
		}

		//Floy Warshall Algorithm for finding 
		//All Pair Shortest Path
		for (int via = 0; via < N; via++)
		{
			for (int from = 0; from < N; from++)
			{
				for (int to = 0; to < N; to++)
				{
					a[from][to] = min(a[from][to], a[from][via] + a[via][to]);
				}
			}
		}

		ans = 0;

		scanf("%d%d", &s, &d);

		//Just like the Power Puff Girls problem, we are taking the max
		//finally, because we need the minimun time, when all the commandos would have
		//reached the destination, thus max() to find the commando who reached the destination last.
		//Hence all the commandos reached the destination, ending the mission.
		for (int i = 0; i < N; i++)
		{
			ans = max(ans, a[i][s] + a[i][d]); //Distance from 's' -> 'i' and 'i' -> 'd'
		}

		printf("Case %d: %d\n", ++testCase, ans);
	}

	return 0;
}