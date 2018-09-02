// 1. Run a BFS from any node and determine the farthest node from it and name this node as 'farthestNode'
//
// 2. Run another BFS from but this time from 'farthestNode' and save all node’s distance from 'farthestNode' 
// into dist[] array. And determine the farthest node from the source 'farthestNode', and save it as the new 'farthestNode'
//
// 3. Run another BFS from the new 'farthestNode' and save all nodes distance from 'farthestNode' into distOther[] array.
//
// 4. Now print for all node max(dist[node], distOther[node]).



#include <bits/stdc++.h>

using namespace std;

vector<int> graph[30005],cost[30005];
 
int dist[30005], distOther[30005];
int farthestNode, maximum, n;
 
void BFS(int source)
{
    dist[source] = 0; //Initial position, so distance is '0'
    
    queue<int>Q;
    Q.push(source);

    while (!Q.empty())
    {
        int u = Q.front(); //Here u is the top node in the queue
        Q.pop();

        //distance for u is greater than maximum distance, so now this is the new maximum distance
        if (dist[u] > maximum)
        {
            maximum = dist[u];
            farthestNode = u; //node for which is farthest from the source node.
        }

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i]; //adjcacent node

            //This place has not been visited before
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + cost[u][i]; //Current distance = previous distances covered + cost for travelling to the current node
                Q.push(v);
            }
        }
    }
}
 
void BFS_Another(int source)
{
    distOther[source] = 0;
    
    queue<int>Q; //Initial position, so distance is '0'
    Q.push(source);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i]; //adjacent node
            
            //This place has not been visited before
            if(distOther[v] == -1)
            {
                distOther[v] = distOther[u] + cost[u][i]; //Current distance = previous distances covered + cost for travelling to the current node
                Q.push(v);
            }
        }
    }
}
 
void allclear()
{
    for (int i = 0; i <= n; i++)
    {
        graph[i].clear();
        cost[i].clear();
        dist[i] = -1;
        distOther[i] = -1;
    }

    maximum = -1;
    farthestNode = -1;
}
 
int main()
{
    int T,testCase = 0, u, v, c;
    
    scanf("%d", &T);
 
    while (T--)
    {
        scanf("%d", &n);
        
        allclear(); //Clear previous data

        for (int i = 0; i < n - 1; i++)
        {
            scanf("%d%d%d", &u, &v, &c);

            graph[u].push_back(v);
            graph[v].push_back(u);

            cost[u].push_back(c);
            cost[v].push_back(c);
        }

        //Run a BFS from any node and determine the farthest node from it and name this node as farthestNode
        BFS(0);
        
        //Initializing dist as -1, as we need to run BFS again
        //and store the distance from the farthestNode
        for (int i = 0; i <= n; i++)
        {
            dist[i] = -1;
        }

        maximum = -1; //Initializing maximum as -1, as we need to run BFS again
        
        //Run another BFS but this time from the 'farthestNode' calculated from previous BFS 
        //and save all node’s distance from 'farthestNode' into dist[] array.
        //Now determine the farthest node from 'farthestNode' which was given as a source.
        //And override it with the new 'farthestNode'
        BFS(farthestNode);

        //Run another BFS with the new 'farthestNode'
        //Run another BFS from 'farthestNode' and save all nodes distance from 'farthestNode' into distOther[] array.
        BFS_Another(farthestNode);
        
        printf("Case %d:\n", ++testCase);
        
        //Print the distance of the farthest node from each node.
        for(int i = 0; i < n; i++)
        {
            printf("%d\n", max(dist[i], distOther[i]));
        }

    }

    return 0;
}