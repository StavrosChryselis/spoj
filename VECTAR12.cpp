/*
****************************************************************
****************************************************************
-> Coded by Stavros Chryselis				   
-> Visit my github for more solved problems over multiple sites 
-> https://github.com/StavrosChryselis			  
-> Feel free to email me at stavrikios@gmail.com	
****************************************************************
****************************************************************
*/

#include <stdio.h>
 
#define MOD 1000000007
using namespace std;
 
int N, K;
int DP[7007][7007];
 
inline void init()
{
	int i, j;
	
	DP[0][0] = 1;
 
	for (i = 1; i < 7000; i++)
	{
		DP[i][0] += DP[i - 1][0] + DP[i - 1][1];
		
		if (DP[i][0] >= MOD)
			DP[i][0] -= MOD;
 
		for (j = 1; j <= i; j++)
		{
			DP[i][j] += DP[i - 1][j - 1] + DP[i - 1][j];
 
			if (DP[i][j] >= MOD)
				DP[i][j] -= MOD;
 
			DP[i][j] += DP[i - 1][j + 1];
 
			if (DP[i][j] >= MOD)
				DP[i][j] -= MOD;
		}
	}
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
 
	init();
	int T;
 
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%d %d", &N, &K);
		printf("%d\n", DP[N][K]);
	}
 
	return 0;
} 
