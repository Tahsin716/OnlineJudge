#include <bits/stdc++.h>

using namespace std;

int n, m, u, v; //Here m denotes no. of relations, n denotes number of people. u and v denotes the nodes.

//people here denotes no. of people in a dis-joint group, total is the sum of money in the group
//and sum is the total money all together.
int people, total, sum; 

int money[1005];
vector<int> graph[10005];

bool visited[1005];


void dfs(int source)
{
    total += money[source]; //Total money in the group
    people++; //Total no. of people in the group

    visited[source] = 1; //Mark this node as visited

    for (int i = 0; i < graph[source].size(); i++)
    {
        int v = graph[source][i];

        //Not visited this adjacent node before
        if (visited[v] == 0)
        {
            dfs(v);
        }
    }

}

int main()
{

    int T, testCase = 0;

    scanf("%d", &T);

    while (T--)
    {

    	//Clear previous test case data
    	for (int i = 0; i < 10005; i++)
    		graph[i].clear();

    	//Initialize visited as '0'
    	memset(visited, 0, sizeof visited); 

        scanf("%d%d", &n, &m);

        sum = 0;

        for (int i = 0; i < n; i++)
        {
        	scanf("%d", &money[i]);
        	sum += money[i];
    	}

        bool equalDistribution = true; //Flag for checking if the money has been equally distributed or not

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);

            u--,v--; //Since indexing here is given as Index - 1, thus we decrement it to make it '0' based index.

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int average = sum / n; //Average of the sum of money, each person should finally get

        for (int i = 0; i < n; i++)
        {

            people = 0;
            total = 0;

            if (visited[i] == 0)
            {
                dfs(i);

                //If the total money in a group is not divisible by the no. of
                //people in that group, then there can not be equal distribution of
                //the money.
                if (total % people != 0)
                {
                    equalDistribution = false;
                    break;
                }
                else
                {
                	//If the average of the sum of money, is not equal
                	//to the total money in the groups divided by the total no. of
                	//people in that group, then there cannot be any equal distribution of 
                	//money.
                    if(average != total / people)
                    {
                        equalDistribution = false;
                        break;
                    }
                }
            }

        }

        //If money can be equally distributed then "Yes" otherwise "No"
        printf("Case %d: %s\n", ++testCase, (equalDistribution)? "Yes" : "No"); 
    }

    return 0;
}