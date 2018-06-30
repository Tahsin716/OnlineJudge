#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

string str, rev_str;
int n;
int dp[105][105];

int rec(int first_index, int second_index)
{
	if (first_index == n || second_index == n) return 0;

	if (dp[first_index][second_index] != -1) return dp[first_index][second_index];

	int ret = 0;

	if(str[first_index] == rev_str[second_index])
	{
		ret = 1 + rec(first_index + 1, second_index + 1);
	}
	else
	{
		int a = rec(first_index + 1, second_index);
		int b = rec(first_index, second_index + 1);

		ret = max(a, b);
	}

	return dp[first_index][second_index] = ret;
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
		memset(dp, -1, sizeof(dp));

		cin >> str;
        n = str.size();

		rev_str = str;
		reverse(rev_str.begin(), rev_str.end());


		int result = rec(0, 0);

		int ans = n - result;
		printf("Case %d: %d\n", testCase, ans);
	}

	return 0;
}
