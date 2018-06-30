#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

int length;
int dp[1005];
string s;

bool isPalindrome(int left, int right)
{
	while (left < right)
	{
		if (s[left] != s[right])
			return false;

		left++;
		right--;
	}

	return true;
}

int rec(int position)
{
	if (position == length) return 0;

	if (dp[position] != -1)
		return dp[position];

	int ret = INT_MAX;

	for (int i = position; i < length; i++)
	{
		if (isPalindrome(position, i))
		{
			ret = min(ret, 1 + rec(i + 1));
		}
	}

	return dp[position] = ret;
}


int main()
{
	int T, ans;
	scanf("%d", &T);

	for (int testCase = 1; testCase <= T; testCase++)
	{
		cin >> s;
		length = (int) s.size();

		memset(dp, -1, sizeof dp);

		ans = rec(0);

		printf("Case %d: %d\n", testCase, ans);
	}

	return 0;
}