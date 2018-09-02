#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int INF = 0X3f3f3f3f; // This equals to 1061109567, we are not using INT_MAX as it can cause data overflow.

struct data
{
    int row , column , num; //row, column and number of moves
};


int m, n; //Here m represents number of row, while n represents number of columns
int vis[30][30];

//va represents the number of moves required by the the count of knights
//to reach the given row and column.
int va[110][30][30]; 

int moves[8][2] = { {1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1} }; //The 8 different moves of the knight.
char map[30][30]; //The 2-D grid

void bfs(int row , int column , int total , int count)
{
    memset(vis , 0 , sizeof vis);

    queue<data>q;

    data top;
    
    top.row = row , top.column = column , top.num = 0;
    vis[top.row][top.column] = 1;

    va[count][row][column] = 0;

    q.push(top);

    while(!q.empty())
    {
        data u = q.front(); //Here u is the data at the top

        //The knight has 8 different moves, so we will loop 8 times
        //and move in the 8 different directions, and check whether or not the
        //move is valid.
        for(int i = 0 ; i < 8 ; i++)
        {
            data v = u; //For the top data u, we are going to traverse in the 8 possible directions.

            //Moving in the 8 directions
            v.row += moves[i][0]; 
            v.column += moves[i][1];

            //If the move is valid, that is; it is not out of bounds
            if(v.row >= 0 and v.row < m and v.column >= 0 and v.column < n)
            {
                v.num++;
                int temp;

                //If the number of moves exceeds the total no. of moves
                if (v.num > total)
                {
                    //Check if the number of moves is divisible by total
                    if (v.num % total == 0)
                    {
                        temp = v.num / total;
                    }
                    //If not add +1, as it is integer division the remainder will be lost.
                    else
                    {
                        temp = v.num / total + 1;
                    }
                }
                //If num has not exceeded total no. of moves
                else
                {
                    temp = 1;
                }

                //If this square block has not been visited
                if (vis[v.row][v.column] == 0)
                {
                    va[count][v.row][v.column] = temp;
                    vis[v.row][v.column] = 1;

                    q.push(v);
                }

            }
        }

        q.pop();
    }

}


int main()
{
    int T, testCase = 0, ans = 0;
    
    scanf("%d", &T);

    while (T--)
    {
        memset(va , -1 , sizeof va);
        ans++;

        cin >> m >> n;

        int checkCount = INF , count = 0;

        for(int i = 0 ; i < m ; i++)
        {
            cin >> map[i];
        }


        for (int i = 0 ; i < m ; i++)
        {
            for (int j = 0 ; j < n ; j++)
            {
                if(map[i][j] != '.')
                {
                    count++; //For every knight, count++.

                    bfs(i , j , map[i][j] - '0' , count); //row, column, total no. of moves, count of knights
                }
            }
        }


        for (int i = 0 ; i < m ; i++)
        {
            for (int j = 0 ; j < n ; j++)
            {
                int sum = 0;

                for (int k = 1 ; k <= count ; k++)
                {
                    sum += va[k][i][j]; // va[count][row][column] containing the number of moves

                    //Check if there are no knights placed in this row and column
                    if(va[k][i][j] == -1)
                    {
                        sum = INF;
                        break;
                    }
                }

                checkCount = min(checkCount, sum);
            }
        }

        printf("Case %d: %d\n", ++testCase, (checkCount == INF)? -1 : checkCount);

    }

    return 0;
}