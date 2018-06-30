#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int lcs(const string &str, const string &rev_str)
{
	int n = str.size(), m = rev_str.size();

	int dp[n + 1][m + 1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{

			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if (str[i-1] == rev_str[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[n][m];
}

int main()
{

	#ifdef SAMPLE_TEST
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // SAMPLE_TEST

	int T, n;
	scanf("%d", &T);

	string str, rev_str;

	for (int testCase = 1; testCase <= T; testCase++)
	{
		cin >> str;
		n = str.size();

		rev_str = str;
		reverse(rev_str.begin(), rev_str.end());

		int result = lcs(str, rev_str);

		int ans = n - result;
		printf("Case %d: %d\n", testCase, ans);
	}

	return 0;
}
