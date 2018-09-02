#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1005], cost[1005];

int dist[1005], n;

//There can be multiple roads between same pair of junctions
//That is road u and v can repeat with different w
//thus we need to input the minimum w.
//same condition was given in LOJ - 1002 Country Roads
//but we didn't need to take care of it as w was given in descending order.
int minCost[1005][1005]; 

//The node will keep the vertex and the minimum distance to reach it
struct node
{
    int u, dis;

    //Constructor for taking the node and the distance traversed to reach it
    node(int a, int b)
    {
        u = a, dis = b;
    }

    //Since we are using a priority queue, we are overloading the operator
    //to compare the vertices pushed into the queue, where we will put the
    //smaller vertices first, as in Dijkstra's Algorithm, the smaller nodes
    //from the source vertex are traversed first.
    bool operator < (const node & temp)const {
        return temp.dis < dis;
    }
};


void dijkstra(int source)
{
    priority_queue<node> Q;	//Priority Queue for keeping the vertex and the minimum distance to reach it
    
    //First we will mark all the cities as a large number,
    //which will indicate that this cities have not been visited
    //finally if this cities are not visited, then ans for this cities will be imposssible
    for (int i = 0; i < 1005; i++)
    	dist[i] = 100001;

    dist[source] = 0;
    Q.push(node(source, 0)); //Since we are initially in source's position so its distance is '0'.

    while (!Q.empty())
    {
        node top = Q.top(); //The top most node
        Q.pop();

        int u = top.u; //The top node's vertex
        
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i]; //Adjacent vertex

            //The regular formula for checking the distance in dijkstra's algorithm
            if (dist[u] + cost[u][i] < dist[v])
            {
                dist[v] = dist[u] + cost[u][i];
                Q.push(node(v, dist[v]));
            }
        }
    }
}

int main()
{
    int T, testCase = 0, m, u, v, w;
    
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d%d", &n, &m);

        //Initializing minCost with INF
        for (int i = 0; i < 1005; i++)
        	for (int j = 0; j < 1005; j++)
        		minCost[i][j] = 1001;

        //Here although two junctions, u and v can have multiple roads w
        //and thus we have to take the minimum weighted road, but if the junctions u and v
        //are repeated the distance are given in decreasing order, so we are always pushing
        //the smallest w as the cost, in the vector. Hence this condition is readily taken care of.
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);

            graph[u].push_back(v);
            graph[v].push_back(u);

            //Handling the weight of the repeated roads, we will take the
            //minimum one.
            minCost[u][v] = min(minCost[u][v], w);
            minCost[v][u] = min(minCost[v][u], w);

            cost[u].push_back(minCost[u][v]);
            cost[v].push_back(minCost[v][u]);
        }

        //Tanvir lives in the 1st junction whereas Atiq lives in the Nth junction
        //and so if dist[n] == INF, that means it is impossible to travel to Nth junction
        dijkstra(1);

        printf("Case %d: ", ++testCase);

        //We cannot reach the Nth junction
        if (dist[n] == 100001)
    	{
    		printf("Impossible\n");
		}
        else
        {
        	printf("%d\n", dist[n]);
        } 

        //Removin data from previous test case
        for (int i = 0; i < 1005; i++)
        {
        	graph[i].clear();
        	cost[i].clear();
        }
    }

    return 0;
}