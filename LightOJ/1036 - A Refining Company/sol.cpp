#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[505][505], radium[505][505], uranium[505][505];

int rec(int row, int col)
{
	if (row < 0 || col < 0) return 0;
	
	if (dp[row][col] != -1)
		return dp[row][col];
		
	int ret = 0;
	ret = max(rec(row - 1, col) + uranium[row][col], rec(row, col - 1) + radium[row][col]);
	
	return dp[row][col] = ret;
}

int main()
{
	int T, m, n, ans;
	scanf("%d", &T);
	
	for (int testCase = 1; testCase <= T; testCase++)
	{
		scanf("%d%d", &m, &n);
		
		memset(uranium, 0, sizeof uranium);
		memset(radium, 0, sizeof radium);
		
		
		for (int row = 0; row < m; row++)
		{
			for(int col = 0; col < n; col++)
			{
				scanf("%d", &uranium[row][col]);
				
				if (col)
				{
					uranium[row][col] += uranium[row][col - 1]; //Prefix Sum
				}
			}
		}
		
		for (int row = 0; row < m; row++)
		{
			for(int col = 0; col < n; col++)
			{
				scanf("%d", &radium[row][col]);
				
				if (row)
				{
					radium[row][col] += radium[row - 1][col]; //Prefix Sum
				}
			}
		}
		
			
		memset(dp, -1, sizeof dp);
		
		ans = rec(m - 1, n - 1);
		printf("Case %d: %d\n", testCase, ans);
	}
	
	return 0;
}