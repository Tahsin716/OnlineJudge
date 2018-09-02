#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int fib[50];
bool binary[50];

int main()
{
	int T, n, testCase = 0, index;

	scanf("%d", &T);

	fib[0] = 1;
	fib[1] = 1;

	for (int i = 2; i <= 45; i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	while (T--)
	{
		scanf("%d", &n);

		index = -1;

		for (int i = 45; i >= 1; i--)
		{

			//It follows a pattern
			if (n >= fib[i])
			{
				if (index == -1)
				{
					index = i; // First bit index
				}

				n = n - fib[i]; 

				binary[i] = true; //Bit is 1
			}
		}

		printf("Case %d: ", ++testCase);

		for (int i = index; i >= 1; i--)
		{
			if (binary[i])
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}

		printf("\n");

		memset(binary, false, sizeof binary);
	}

	return 0;
}