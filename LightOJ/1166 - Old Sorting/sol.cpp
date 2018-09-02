#include <iostream>
#include <stdio.h>

using namespace std;

//As the arr is always a permutation of 1 - n, so we will run a loop of Index-1
//and check:
//
//If a[i] != i, since the array is a permutation of 1 -> n, then a[i] should be equal
//to the index i, if not then run another loop and swap a[i] with a[j], if it is equal
//to the index j.
int main()
{
	int n;
	int a[1000];
	int ans;
	int T, testCase = 0;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);
		
		ans = 0; //Initially no swap has been made

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}

		//Checking whether a[i] != i, then a swap has to be made
		//So we will run another for loop and check if a[i] == j
		//If yes then this two elements are not in their respective index,
		//and so we will swap them, and increment ans.
		for (int i = 1; i <= n; i++)
		{
			if(a[i] != i)
			{
				
				//We will run 'j' from 'i + 1'
				for (int j = i + 1; j <= n; j++)
				{
					//Since the array is a permutation of 1 -> n
					//So we will just place a[i] where j == a[i]
					//That is index j == a[i].
					if(a[j] == i)
					{
						swap(a[j], a[i]);
						ans++;

						break; //We found the ans so break the loop
					}

				}
			}

		}

		printf("Case %d: %d\n", ++testCase, ans);

	}


}