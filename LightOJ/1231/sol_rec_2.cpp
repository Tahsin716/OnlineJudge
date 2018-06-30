#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, k, A[52], C[52];
int dp[52][1002];

int M = 1e8 + 7;

int rec(int index, int sum)
{

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

	for (int taken = 0; taken <= C[index] and (taken * A[index] + sum) <= k; taken++)
	{
		ans += rec(index + 1, sum + taken * A[index]);
		ans %= M;
	}

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
			scanf("%d", &A[i]);

		for (int i = 0; i < n; i++)
			scanf("%d", &C[i]);

		memset(dp, -1, sizeof(dp));

		int ans = rec(0, 0);

		printf("Case %d: %d\n", testCase, ans);
	}

	return 0;
}
