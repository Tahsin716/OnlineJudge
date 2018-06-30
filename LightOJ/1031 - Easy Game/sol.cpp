#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

int dp[105][105];
int arr[105];
int n;

int rec(int firstIndex, int lastIndex)
{

	if (firstIndex > lastIndex) return 0;

	if (dp[firstIndex][lastIndex] != -1)
		return dp[firstIndex][lastIndex];

	int temp = 0, difference = INT_MIN;

	for (int k = firstIndex; k <= lastIndex; k++)
	{
		temp += arr[k];
		difference = max(difference, temp - rec(k + 1, lastIndex));
	}

	temp = 0;

	for (int k = lastIndex; k >= firstIndex; k--)
	{
		temp += arr[k];
		difference = max(difference, temp - rec(firstIndex, k - 1));
	}

	return dp[firstIndex][lastIndex] = difference;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int testCase = 1; testCase <= T; testCase++)
	{
		
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		memset(dp, -1, sizeof dp);

		int ans = rec(0, n - 1);

		printf("Case %d: %d\n", testCase, ans);
	}

	return 0;
}
