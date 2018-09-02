#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long dp[51][51][51];
int n, k, m;

long long rec(int totalUnit, int totalBar, int atmostEachUnit)
{
	if (totalUnit == 0 && totalBar == 0) return 1;

	// Tricky condition: totalUnit > 1 && totalBar == 0
	if ((totalUnit == 0 && totalBar > 0) or (totalUnit > 1 && totalBar == 0)) return 0; 

	if (totalUnit < 0 or totalBar < 0) return 0;

	if (dp[totalUnit][totalBar][atmostEachUnit] != -1)
		return dp[totalUnit][totalBar][atmostEachUnit];

	long long ret = 0;

	//Selecting consecutive bars, of variying units
	for (int i = 1; i <= atmostEachUnit; i++)
	{
		ret += rec(totalUnit - i, totalBar - 1, atmostEachUnit);
	}

	return dp[totalUnit][totalBar][atmostEachUnit] = ret;
}

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);

	memset(dp, -1, sizeof dp); // Do memset only once else, you'll end up with TLE

	while (T--)
	{
		scanf("%d%d%d", &n, &k, &m);

		printf("Case %d: %lld\n", ++testCase, rec(n, k, m));
	}

	return 0;
}