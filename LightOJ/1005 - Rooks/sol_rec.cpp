#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

unsigned long long backtrack(int row, int col, int k)
{
	if (k == 0)
	{
		return 1;
	}

	if (row < k or col < k)
    {
        return 0;
    }

	if (row == k or col == k)
	{
		int mx = max(row, col);
		unsigned long long count = 1;

		for (int i = 1; i <= k; i++)
		{
			count *= (mx + 1) - i;
		}

		return count;
	}

	return row * backtrack(row - 1, col - 1, k - 1) + backtrack(row, col - 1, k);
}


int main()
{

	#ifdef SAMPLE_TEST
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // SAMPLE_TEST

	int n, k, T;
	unsigned long long ans;

	scanf("%d", &T);

	for (int testCase = 1; testCase <= T; testCase++)
	{
		scanf("%d%d", &n, &k);
		ans = backtrack(n, n, k);

		printf("Case %d: %llu\n", testCase, ans);
	}

	return 0;
}
