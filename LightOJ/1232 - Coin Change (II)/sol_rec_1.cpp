/**
	Time Limit Exceeded
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, k, A[105];
int dp[105][10005];
int M = 1e8 + 7;

int rec(int index, int taken, int sum)
{

    if (sum > k)
    {
        return 0;
    }

    if (sum == k)
	{
		return 1;
	}

	if (index == n)
	{
		return 0;
	}


	if (dp[index][sum] != -1)
	{
		return dp[index][sum];
	}


	int ans = 0;
	if (taken < k)
	{
		ans += rec(index, taken + 1, sum + A[index]);
	}

	ans %= M;

	ans += rec(index + 1, 0, sum);
	ans %= M;

	return dp[index][sum] = ans;
}


int main()
{

	#ifdef SAMPLE_TEST
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // SAMPLE_TEST

	int T;
	scanf("%d", &T);

	for (int testCase = 1; testCase <= T; testCase++)
	{
		scanf("%d%d", &n, &k);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
		}

		memset(dp, -1, sizeof(dp));
		int ans = rec(0, 0, 0);

		printf("Case %d: %d\n", testCase, ans);
	}


	return 0;
}
