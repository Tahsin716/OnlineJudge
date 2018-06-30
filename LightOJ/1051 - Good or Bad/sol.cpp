#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string s;
int dp[51][4][6]; // 50 characters, 3 vowels & 5 consonants
int n;
string ans[4] = {"", "GOOD", "BAD", "MIXED"};

bool check(char c)
{
	return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int rec(int index, int vowel, int consonant)
{
	if (vowel == 3 || consonant == 5) return 2;

	if (index == n) return 1;

	if (dp[index][vowel][consonant] != -1)
		return dp[index][vowel][consonant];

	int ret = 0;

	if (s[index] == '1')
		ret   = ret | rec(index + 1, vowel + 1, 0);

	if (s[index] == '0')
		ret = ret | rec(index + 1, 0, consonant + 1);

	
	if (s[index] == '?')
		ret = ret | rec(index + 1, vowel + 1, 0) | rec(index + 1, 0, consonant + 1); //For '?' we can place either a vowel or a consonant

	return dp[index][vowel][consonant] = ret;
}

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);

	while (T--)
	{
		cin >> s;
		n = (int) s.size();

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '?')
				continue;

			s[i] = check(s[i]) + '0';
		}

		memset(dp, -1 ,sizeof dp);

		printf("Case %d: %s\n", ++testCase, ans[rec(0, 0, 0)].c_str() ); 
	}

	//.c_str() Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) 
	//representing the current value of the string object.

	return 0;
}