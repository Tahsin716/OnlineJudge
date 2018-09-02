#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

int dp[105][105][105], books[105];
int n;

int rec(int position, int left, int right)
{
	if (position > n) return 0;

	if (dp[position][left][right] != -1)
		return dp[position][left][right];

	int ret = 0;

	if (books[left] <= books[position] and books[position] <= books[right])
	{
		ret = max(ret, 1 + rec(position + 1, position, right)); // Putting the book in left side of the shelf; add 1 
	}

	if (books[left] <= books[position] and books[position] <= books[right])
	{
		ret = max(ret, 1 + rec(position + 1, left, position)); // Putting the book in right side of the shelf; add 1
	}

	ret = max(ret, rec(position + 1, left, right)); // Not putting the book in the shelf

	return dp[position][left][right] = ret;
}

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
			scanf("%d", &books[i]);

		memset(dp, -1, sizeof dp);

		books[0] = INT_MIN;
		books[n + 1] = INT_MAX; //Calculate from negative infinity to positive infinity

		printf("Case %d: %d\n", ++testCase, rec(1, 0, n + 1));
	}

	return 0;
}