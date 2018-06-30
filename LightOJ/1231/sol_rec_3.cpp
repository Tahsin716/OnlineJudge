/**
	Coin change - I

	If I take dp[52][1002] --> 2 state
	instead of dp[52][52][1002] ---> 3 state

	the answer doesn't match, but if I do that for Coin Change - II it works although it results in TLE
	but all the testcases from udebug matches.


	The solution below is coin change I
*/


#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int M = 1e8 + 7;

int n, k, A[52], C[52];
int dp[52][1002];

int rec(int index, int taken, int sum)
{
	if (sum > k) return 0;
	if (sum == k) return 1;
	if (index == n) return 0;

	if (dp[index][sum] != -1) 
		return dp[index][sum];

	int ret = 0;

	if (taken < C[index])
		ret += rec(index, taken + 1, sum + A[index]);

	ret %= M;

	ret += rec(index + 1, 0, sum);
	ret %= M;

	return dp[index][sum] = ret;
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

		int ans = rec(0, 0, 0);

		printf("Case %d: %d\n", testCase, ans);
	}

	return 0;
}