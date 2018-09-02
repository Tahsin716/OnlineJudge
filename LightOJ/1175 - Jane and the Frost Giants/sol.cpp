#include <bits/stdc++.h>

using namespace std;

const int dx[] = {+1, -1, 0, 0}; // column + 1, column - 1, column, column
const int dy[] = {0, 0, +1, -1}; // row, row, row + 1, row - 1

const int INF = 1000000;
 
char graph[201][201];

int graphJane[201][201]; //Amount of time taken by Jane to reach this co-ordinate
int graphFire[201][201]; //Amount of time taken for fire to reach this co-ordinate

bool visited[201][201];
 
int row, column;

vector< pair<int, int> > fireData; //Vector containing co-oridinates where there is fire.
pair<int, int> positionJane; //Jane's initial position
 
//Check whether the position is out of bounds
//or if this position has been visited before or whether, there is an obstacle here or not. 
bool testFire(pair<int, int> temp)
{
    if (temp.first < 0 or temp.first >= row or temp.second < 0 or temp.second >= column)
        return 0;

    if (visited[temp.first][temp.second] or graph[temp.first][temp.second] != '.')
    	return 0;

    return 1;
}
 
//Check whether the position is out of bounds
//or if this position has been visited before or whether, there is an obstacle here or not.  
bool testJane(pair<int, int> temp)
{
    if (temp.first < 0 or temp.first >= row or temp.second < 0 or temp.second >= column)
        return 0;

    if (visited[temp.first][temp.second] or graph[temp.first][temp.second] != '.')
    	return 0;

    return 1;
}
 
//BFS for finding the time taken by fire to reach each co-ordinate
void bfsFire()
{
	memset(visited, 0, sizeof visited);
	memset(graphFire, INF, sizeof graphFire);
 
    queue< pair<int, int> > Q;
    pair<int, int> u, v; //u is used for top node, while v is used for the adjacent nodes(Nort, East, South, West).

    //First graphFire was initialized as INF
    //now we are putting '0', where ever there is fire
    //and also marking those co-ordinates as visited.
    //finally pushing the co-oridinates into the queue.
    for(int i = 0; i < fireData.size(); i++)
    {
        u = fireData[i];
        graphFire[u.first][u.second] = 0; //mark places where there is fire as '0', as it took '0' minutes for fire to reach this place

        Q.push(u);
        visited[u.first][u.second] = 1; //mark the position as visited
    }

    while (!Q.empty())
    {
        u = Q.front(); // Here u is the pair of co-ordinates at the top
        Q.pop();

        //Loop four times for the four different directions
        //row + 1, row - 1, column + 1, column - 1
        for (int i = 0; i < 4; i++)
        {
            v.first = u.first + dx[i];
            v.second = u.second + dy[i];

            if (testFire(v))
            {
            	//Postion of fire in the graph is equal to, postion of fire previosly + 1
            	//as is spreading, both horizontally and vertically.
                graphFire[v.first][v.second] = graphFire[u.first][u.second] + 1; 
                
                visited[v.first][v.second] = 1;
                Q.push(v);
            }
        }
    }
}
 
int bfsJane(pair<int, int> source)
{
    memset(visited, 0, sizeof visited);
    memset(graphJane, INF, sizeof graphJane);

    visited[source.first][source.second] = 1; //mark Jane's initial position as visited
    
    pair<int, int> u,v; //u is used for top node, while v is used for the adjacent nodes(Nort, East, South, West).

    //Jane is initially here so it took her '0' minutes to get here
    //We will then calculate how much time Jane takes to reach each co-ordinates
    //before managing to escape or not.
    graphJane[source.first][source.second] = 0; 
 
    queue< pair<int, int> > Q;
    Q.push(source);

    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();

        //Jane has managed to successfully escape the maze
        //so return the amout of time she took to escape
        if(u.first == 0 or u.first == row - 1 or u.second == 0 or u.second == column - 1)
            return graphJane[u.first][u.second];

        //Loop four times for the four different directions
        //row + 1, row - 1, column + 1, column - 1
        for (int i = 0; i < 4; i++)
        {
            v.first = u.first + dx[i];
            v.second = u.second + dy[i];

            // Performing testJane for out of bounds and other tests
            //
            // While also checking whether the time needed by fire to reach this co-ordinate
            // is higher than the time needed by Jane to get to this co-ordinate. If higher, that
            // means Jane got here first before fire spread to this co-ordinate, and thus survived.
            if(testJane(v) and (graphFire[v.first][v.second] > graphJane[u.first][u.second] + 1))
            {
            	graphJane[v.first][v.second] = graphJane[u.first][u.second] + 1;

                visited[v.first][v.second] = 1;
                Q.push(v);
            }
        }
    }

    return -1; //Jane couldn't get out of the maze before the fire spread.
}
 
 
int main()
{
    int T, testCase = 0;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d%d", &row, &column);

        for (int i = 0; i < row; i++)
        {
        	for (int j = 0; j < column; j++)
        	{
        		cin >> graph[i][j];

	            if (graph[i][j] == 'J')
	            {
	                positionJane.first = i, positionJane.second = j;
	            }
	            else if (graph[i][j] == 'F')
	            {
	                fireData.push_back(make_pair(i, j));
	            }
        	}
        }
 
        bfsFire(); //For calculating the time taken by fire to spread to each co-ordinate

        int ans = bfsJane(positionJane); //Time taken by Jane to get out of the maze

        printf("Case %d: ", ++testCase);

        //Jane was not able to escape the maze
        if (ans == -1)
        {
            printf("IMPOSSIBLE\n");
        }
        //Jane managed to escape the maze
        //The last minute for getting out is not calculated, as it will be out of bounds,
        //since this position is out of the graph, thus ans + 1.
        else
        {
            printf("%d\n", ans + 1); 
        }

        fireData.clear();
    }

    return 0;
}