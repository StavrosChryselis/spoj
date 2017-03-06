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
#define min(a,b) ((a<b)?a:b)
int DP[501][101];
int MONEY[501][101];
int FUN[101];
int COST[101];
 
int main()
{
	int budget, N;
	int i, j;
	
	//freopen("input.txt","r",stdin);
 
	scanf("%d %d", &budget, &N);
 
	while(budget != 0 && N!=0)
	{
		for(i=0; i<=budget; i++)
			DP[i][0]=MONEY[i][0]=0;
 
		for(i=0; i<=N; i++)
			DP[0][i]=MONEY[i][0]=0;
 
		for(i=1; i<=N; i++)
			scanf("%d %d", &COST[i], &FUN[i]);
 
		for(i=1; i<=budget; i++)
			for(j=1; j<=N; j++)
			{
				if(COST[j]<=i)
				{
					if(FUN[j]+DP[i-COST[j]][j-1]>DP[i][j-1])
					{
						DP[i][j]=FUN[j]+DP[i-COST[j]][j-1];
						MONEY[i][j]=COST[j] + MONEY[i-COST[j]][j-1];
					}
 
					else if(FUN[j]+DP[i-COST[j]][j-1]==DP[i][j-1])
					{
						DP[i][j]=DP[i][j-1];
						MONEY[i][j]=min(COST[j] + MONEY[i-COST[j]][j-1], MONEY[i][j-1]);
					}
 
					else
					{
						DP[i][j]=DP[i][j-1];
						MONEY[i][j]=MONEY[i][j-1];
					}
				}
				else
				{
					DP[i][j]=DP[i][j-1];
					MONEY[i][j]=MONEY[i][j-1];
				}
			}
 
		printf("%d %d\n", MONEY[budget][N], DP[budget][N]);
		scanf("%d %d", &budget, &N);
	}
 
	return 0;
} 
