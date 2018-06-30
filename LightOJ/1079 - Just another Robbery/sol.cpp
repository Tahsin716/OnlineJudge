#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

double P[101], dp[101][10001], x;
int bank[101], n;

//The prob of getting caught in one of the two banks = the prob of getting caught in the first or the prob 
//of not getting caught in the first and getting caught in the second.

double rec(int index, int money)
{
	if (money <= 0) return 0;

	if (index < 0) return 1;

	if (dp[index][money] > -1)
		return dp[index][money];

	double ret = 1.79769e+308; // Double Max

	ret = rec(index - 1, money);
	ret = min(ret, P[index] + (1.0 - P[index]) * rec(index - 1, money - bank[index]));

	return dp[index][money] = ret;
}

int main()
{
	int T, testCase = 0, high, low, mid;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%lf %d", &x, &n);

		high = 0, low = 0;

		for (int i = 0; i < n; i++)
		{
			scanf("%d %lf", &bank[i], &P[i]);
			high += bank[i];
		}

		memset(dp, -1, sizeof dp);


		//For precision, since (high + low) / 2 will return an integer
		// so there may be chances of late stages being skipped
		while (high - low >= 4)
		{
			mid = (high + low) / 2;

			if (rec(n - 1, mid) < x)
			{
				low = mid;
			}
			else
			{
				high = mid - 1;
			}
		}

		//Answers are in increasing order
		//So binary search to find the answer
		while (high >= low)
		{
			if (rec(n - 1, high) < x)
				break;

			high--;
		}

		printf("Case %d: %d\n", ++testCase, high);
	}

	return 0;
}