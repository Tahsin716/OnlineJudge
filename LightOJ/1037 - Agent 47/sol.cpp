#include <bits/stdc++.h>

using namespace std;

int N, dp[ (1<<15) + 9], health[16], a[16][16];

/*dp[] array may need maximum index,this index is such a number that
is in binary 15 digit of which bit are set (111111111111111) in decimal 2^15*/

char dmg[16][16];

//-------------Set ,reset, check function-------------

int Set(int N,int pos)
{
    return N=N| (1<<pos);
}

int reset(int N,int pos)
{
    return N=N& ~(1<<pos);
}

bool check(int N,int pos)
{
    return (bool)  (N & (1<<pos));
}

//--------------------bitmask function---------------

int rec(int mask)
{
    if (mask == (1 << N) - 1) return 0;
    
    if(dp[mask] != -1)      
    	return dp[mask];

    int minShot = INT_MAX;

    for(int i = 0; i < N; i++)
    {
        if(check(mask, i) == 0)    //agent is searching for a live one to shoot
        {
            int minHealth = health[i];   //max value is if agent shoot everyone by KM 0.45

            for(int j = 0; j< N; j++)
            {
                if(check(mask, j) == 1) // searching deads to get weapon
                {
                    int ans= ceil( (double)health[i] / (double)(a[j][i]) );
                    //minimize number of shoots to kill this alive man with dead's weapon
                    minHealth = min(minHealth, ans);
                }
            }

            int shot = minHealth + rec(Set(mask, i)); //declaring i as dead and continue next operation
            minShot = min(minShot, shot);
        }
    }
    return dp[mask] = minShot;
}

//----------------main function---------------------

int main()
{
    int T;
    scanf("%d",&T);
    for(int testCase = 1; testCase <= T; testCase++)
    {
        memset(dp,-1,sizeof(dp));

        //----------------taking input

        scanf("%d", &N);
        
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &health[i]);
        }

   
        for(int i = 0; i < N; i++)
        {
            scanf("%s", dmg[i]);

            for(int j = 0; j < N; j++)
            {
                a[i][j] = dmg[i][j] - '0';

                if (a[i][j] == 0)
                    a[i][j] = 1;   //to remove 0 value from matrix nor minimized value would be 0
            }
        }


        int n = 0;
        // in bit sequence 0 is live,1 is dead(that can supply agent a weapon)

        int minShot = INT_MAX;

        for(int i = 0; i < N; i++)
        {
            int shot = health[i] + rec(Set(n, i)); //make this man dead by Set bit to 1
            
            minShot = min(minShot, shot);
        }

        printf("Case %d: %d\n",testCase, minShot);
    }
    return 0;

}