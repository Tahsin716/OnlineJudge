#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int dp[202][102];
int data[202][102];
int n;

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
        scanf("%d", &n);
        memset(data, 0, sizeof(data));

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                scanf("%d", &data[i][j]);


        for (int i = n; i < 2*n - 1; i++)
            for (int j = 0; j < 2*n -1 - i; j++)
                scanf("%d", &data[i][j]);

        dp[0][1] = data[0][0];

        for (int i = 1; i < n; i++)
            for (int j = 0; j <= i; j++)
                dp[i][j+1] = data[i][j] + ((dp[i-1][j+1] < dp[i-1][j]) ? dp[i-1][j] : dp[i-1][j+1]);


        for (int i = n; i < 2*n - 1; i++)
            for (int j = 0; j < 2*n -1 - i; j++)
                dp[i][j+1] = data[i][j] + ((dp[i-1][j+1] < dp[i-1][j+2]) ? dp[i-1][j+2] : dp[i-1][j+1]);

        int ans = dp[2*n -2][1];

        printf("Case %d: %d\n", testCase, ans);
    }
}
