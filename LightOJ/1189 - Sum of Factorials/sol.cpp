#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

long long factorial[22];

void calcFactorial()
{
    factorial[0] = 1;

    for (int i = 1; i <= 20; i++)
    {
       factorial[i] = factorial[i - 1] * i;
    }
}

int main()
{
    #ifdef SAMPLE_TEST
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // SAMPLE_TEST

    calcFactorial();

    int testCase;
    long long n;

    scanf("%d", &testCase);

    for (int i = 1; i <= testCase; i++)
    {
        scanf("%lld", &n);
        stack<int> num;
        int index = 20;

        while (index >= 0)
        {
            if (factorial[index] <= n)
            {
                n -= factorial[index];
                num.push(index);
            }
            index--;
        }

        if (n == 0)
        {
            printf("Case %d: ", i);

            while (num.size() != 1)
            {
                printf("%d!+", num.top());
                num.pop();
            }

            printf("%d!\n", num.top());
            num.pop();
        }
        else
        {
            printf("Case %d: impossible\n", i);
        }
    }

    return 0;
}

