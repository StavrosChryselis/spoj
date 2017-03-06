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
#define max(a,b) ((a>b)?a:b)
 
int dp[2][2000001];
int V[501], W[501];
int N, K;
 
int main()
{
	int i, j;
 
 
	scanf("%d %d", &K, &N);
 
	for(i=1; i<=N; i++)
		scanf("%d %d", &V[i], &W[i]);
 
	for(j=1; j<=N; j++)
		for(i=1; i<=K; i++)
		{
			if(i-W[j]>=0)
				dp[j%2][i]=max(V[j]+dp[(j-1)%2][i-W[j]], dp[(j-1)%2][i]);
			else
				dp[j%2][i]=dp[(j-1)%2][i];
		}
 
	printf("%d\n", dp[N%2][K]);
 
	return 0;
} 
