#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int a[1000][4];

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

		for (int i = 0; i < N; i++)
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);

		for (int i = 1; i < N; i++)
		{
			a[i][0] += min(a[i - 1][1], a[i - 1][2]);
			a[i][1] += min(a[i - 1][0], a[i - 1][2]);
			a[i][2] += min(a[i - 1][0], a[i - 1][1]);
		}

		int ans = min(a[N - 1][0], min(a[N - 1][1], a[N - 1][2]));

		printf("Case %d: %d\n", testCase, ans);
	}

	return 0;
}
