#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, k, ans;
int ways[10005], coin[105];
int M = 1e8 + 7;

int solve()
{
	for (int index = 0; index < n; index++)
	{
		for (int taken = 1; taken <= k; taken++)
		{
			if (coin[index] <= taken)
			{
				ways[taken] = ways[taken] + ways[taken - coin[index]];
			}

			if (ways[taken] > M)
			{
				ways[taken] %= M;
			}
		}
	}

	return ways[k];
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

		ways[0] = 1;

		for (int i = 1; i <= k; i++)
		{
			ways[i] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &coin[i]);
		}

		ans = solve();

		printf("Case %d: %d\n", testCase, ans);

	}

	return 0;
}
