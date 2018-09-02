#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000;

int minCost[105][105];

int main()
{

	int T, testCase = 0, n, m, u, v, w;

    scanf("%d", &T );

    while (T--) 
    {
        scanf("%d %d", &n, &m);


        //All Pair Shortest Path Problem
		//First we will initialize the array with all, indices as INF
		//Except self-loop, which shall be Zero.
		//We will use Floyd Warshall Algorithm for this problem
        for (int i = 1; i <= n; i++)
        {
           for(int j = 1; j <= n; j++)
           {
                minCost[i][j] = INF;
           }

            minCost[i][i] = 0;
        }

        //Here although two junctions, u and v can have multiple roads w
        //and thus we have to take the minimum weighted road, but if the junctions u and v
        //are repeated the distance are given in decreasing order, so we are always pushing
        //the smallest w as the cost, in the vector. Hence this condition is readily taken care of.
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);

            //Handling the weight of the repeated roads, we will take the
            //minimum one.
            minCost[u][v] = min(minCost[u][v], w );
            minCost[v][u] = min(minCost[v][u], w );
        }


        //Floy Warshall Algorithm for finding 
		//All Pair Shortest Path
        for (int via = 1; via <= n; via++)
        {
            for (int from = 1; from <= n; from++)
            {
                for (int to = 1; to <= n; to++)
                {
                    minCost[ from ][ to ] = min(minCost[from][to], minCost[from][via] + minCost[via][to]);
                }
            }
        }

        //If it is not possible to reach the Nth junction
        if( minCost[1][n] >= INF ) 
        {
        	printf("Case %d: Impossible\n", ++testCase);
        }
        else
        { 
        	printf( "Case %d: %d\n", ++testCase, minCost[1][n] );
    	}
    }

    return 0;
}