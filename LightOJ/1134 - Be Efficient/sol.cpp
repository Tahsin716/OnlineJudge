#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[500005], vis[500005];
int N, M;

int main()
{
	int T, testCase = 0;
	long long  ans;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d", &N, &M);

		for (int i = 1; i <= N; i++)
			scanf("%d", &a[i]);

		//Cumulative Sum of all numbers
		for (int i = 1; i <= N; i++)
			a[i] = (a[i - 1] + a[i]) % M;

		ans = 0;
		memset(vis, 0, sizeof vis);

		//Finding subsequence length
		for (int i = 1; i <= N; i++)
		{
			ans += vis[a[i]];
			vis[a[i]]++;

			if (a[i] == 0)
				ans++;
		}

		printf("Case %d: %lld\n", ++testCase, ans);
	}

	return 0;
}