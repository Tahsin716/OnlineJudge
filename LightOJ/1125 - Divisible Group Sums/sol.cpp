#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int num[201];
long long dp[201][11][21]; // N = 200, M = 10, D = 20

int N, Q, D, M;

// ((sum + num[index]) % D + D) % D. This is done to handle negative occurrences.

long long rec(int index, int count, int sum)
{
	if (index < 0)
	{
		if (!count && !sum) return 1;

		return 0;
	}

	if (count < 0)
		return 0;

	if (dp[index][count][sum] != -1)
		return dp[index][count][sum];

	long long ret = rec(index - 1, count - 1, ((sum + num[index]) %D + D) % D) + rec(index - 1, count, sum);

	return dp[index][count][sum] = ret;
}

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d", &N, &Q);

		for (int i = 0; i < N; i++)
			scanf("%d", &num[i]);

		printf("Case %d:\n", ++testCase);

		for (int i = 0; i < Q; i++)
		{
			scanf("%d%d", &D, &M);
			memset(dp, -1, sizeof dp);

			printf("%lld\n", rec(N - 1, M, 0));
		}
	}

	return 0;
}