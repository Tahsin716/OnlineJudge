#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int frequency[26];
long long factorial[26];
string s;
long long n;

void init()
{
	factorial[0] = 1;

	for (int i = 1; i <= 22; i++)
		factorial[i] = factorial[i - 1] * i;
}

void call(int position, long long num)
{
	if (position == 0)
	{
		printf("\n");
		return;
	}

	for (int i = 0; i < 26; i++)
	{
		if (frequency[i] == 0)
			continue;

		long long temp = factorial[position - 1] * frequency[i];

		for (int j = 0; j < 26; j++)
			temp /= factorial[frequency[j]];

		if (num > temp)
		{
			num -= temp;
		}
		else
		{
			frequency[i]--;
			printf("%c", 'a' + i);
			break;
		}
	}

	call(position - 1, num);
}



int main()
{
	init();

	int T, testCase = 0;
	scanf("%d", &T);
	
	while (T--)
	{

		cin >> s >> n;
		int length = (int) s.size();

		memset(frequency, 0, sizeof frequency);

		for (int i = 0; i < length; i++)
			frequency[s[i] - 'a']++;

		long long ans = factorial[length];

		for (int i = 0; i < 26; i++)
			ans /= factorial[frequency[i]];

		printf("Case %d: ", ++testCase);

		if (ans < n)
			cout << "Impossible" << endl;
		else
			call(length, n);
	}


	return 0;
}