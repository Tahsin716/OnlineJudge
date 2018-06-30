#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int dp[201][201];
vector<int> a[201];

int n, v;

int rec(int row, int col)
{
    if (row >= 0 && row < 2*n - 1 && col >= 0 && col < a[row].size())
    {
        if (dp[row][col] != -1)
            return dp[row][col];

        int ret = -1;

        ret = max(ret, rec(row + 1, col) + a[row][col]);

        if (row < n - 1)
        {
            ret = max(ret, rec(row + 1, col + 1) + a[row][col]);
        }
        else if (row >= n - 1)
        {
            ret = max(ret, rec(row + 1, col - 1) + a[row][col]);
        }

        return dp[row][col] = ret;
    }
    else
        return 0;
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
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            a[i].clear();

            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &v);
                a[i].push_back(v);
            }
        }

        int len_half = n - 1;

        for (int i = n; i < 2*n - 1; i++)
        {
            a[i].clear();

            for (int j = 0; j < len_half; j++)
            {
                scanf("%d", &v);
                a[i].push_back(v);
            }
            len_half--;
        }

        printf("Case %d: %d\n", testCase, rec(0,0));
    }

    return 0;
}
