#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int dp[21][4], R[21], G[21], B[21];

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
		scanf("%d", &N);
		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d%d", &R[i], &G[i], &B[i]);

			dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + R[i];
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + G[i];
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + B[i];
		}

		int ans = min(dp[N][0], min(dp[N][1], dp[N][2]));

		printf("Case %d: %d\n", testCase, ans);
	}

	return 0;
}
