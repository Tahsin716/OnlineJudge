#include <iostream>
#include <cstdio>
#include <cstring>

#define check(n, pos) (n & (1 << pos))

#define set(n, pos) (n | (1 << pos))

using namespace std;

int dp[17][100005];
long long a[17][17];
int n;

long long rec(int index, long long vis)
{
	if (index == n) return 0;
	
	if (dp[index][vis] != -1)
		return dp[index][vis];
	
	long long sum = -1;
	
	if (dp[index][vis] == -1)
	{
		for (int j = 0; j < n; j++)
		{
			if (check(vis, j) == 0)
			{
				sum = max(sum, a[index][j] + rec(index + 1, set(vis, j)));
			}
		}
		
		dp[index][vis] = sum;
	}
	
	return dp[index][vis];
}

int main()
{
	int T;
	long long ans;
	scanf("%d", &T);
	
	for (int testCase = 1; testCase <= T; testCase++)
	{
		scanf("%d", &n);
		
		for (int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%lld", &a[i][j]);
		
		memset(dp, -1, sizeof dp);
		
		ans = rec(0, 0);
		printf("Case %d: %d\n", testCase, ans);
	}
	
	return 0;
}