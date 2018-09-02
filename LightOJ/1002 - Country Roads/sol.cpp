#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1005], cost[1005];

const int INF = 20005;
int dist[1005], n;

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
    priority_queue<node> Q; //Priority Queue for keeping the vertex and the minimum distance to reach it
    
    //First we will mark all the cities as a large number,
    //which will indicate that this cities have not been visited
    //finally if this cities are not visited, then ans for this cities will be imposssible
    for (int i = 0; i <= n; i++)
    	dist[i] = 20001;

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

            //Here is a tricky part, usually in dijkstra's algorithm we do this
            //
            // temp = dis[u] + cost[u][v]
            // 		if (temp < dis[v])
            //    		dis[v] = temp;
            //
            //But in this problem there is a certain twist
            //In the question, distance from 0 --> 1, is 2
            //and distance from 1 --> 4, is 8
            //so normally distance from 0 --> 1 --> 4 would be 10.
            //
            //But here we will only take the cost of the maximum road on our path to reach
            //the city, in this case (0 -> 1 -> 4), the max is road (1 -> 4) i.e 8.
            //so max distance will be 8.
            int temp = max(dist[u], cost[u][i]);

            if (temp < dist[v])
            {
                dist[v] = temp;
                Q.push(node(v, dist[v]));
            }
        }
    }
}

int main()
{
    int src, m, u, v, w, T, testCase = 0;
    
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d%d", &n, &m);
        
        //Here although two cities, u and v can have multiple roads w
        //and thus we have to take the minimum weighted road, but if the cities u and v
        //are repeated the distance are given in decreasing order, so we are always pushing
        //the smallest w as the cost, in the vector. Hence this condition is readily taken care of.
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);

            graph[u].push_back(v);
            graph[v].push_back(u);

            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        scanf("%d", &src);
        dijkstra(src);

        printf("Case %d:\n", ++testCase);

        for (int i = 0; i < n; i++)
        {
        	//If it is impossible to reach this city from the source
            if (dist[i] == 20001)
            {
            	printf("Impossible\n");
            }
            //distance traversed to reach this city from the source
            else
            {
             	printf("%d\n", dist[i]);
            }
        }

        //Clearing previous testcase's data
        for (int i = 0; i <= n; i++)
        {
            graph[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}