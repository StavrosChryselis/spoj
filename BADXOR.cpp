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
#include <string.h>
#define MOD 100000007
 
int N, M;
int A[1025], B[1025];
int DP[1025][1025];
 
inline void init()
{
	int i, num;
 
	memset(B, 0, sizeof(B));
 
	for(i=1; i<1025; i++)
		DP[0][i] = 0;
 
	DP[0][0] = 1;
 
	scanf("%d %d", &N, &M);
 
	for(i=1; i<=N; i++)
		scanf("%d", &A[i]);
 
	for(i=0; i<M; i++)
	{
		scanf("%d", &num);
		B[num] = 1;
	}
}
 
 
int main()
{
	int T, t, i, j, sum;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);	
 
	for(t=1; t<=T; t++)
	{
		init();
		sum = 0;
 
		for(i=1; i<=N; i++)
			for(j=0; j<1024; j++)
			{
				DP[i][j] = DP[i-1][j] + DP[i-1][j^A[i]];
				if(DP[i][j]>=MOD)
					DP[i][j] -= MOD;
			}
 
		for(i=0; i<1024; i++)
			if(!B[i])
			{
				sum += DP[N][i];
				if(sum >= MOD)
					sum -= MOD;
			}
 
		printf("Case %d: %d\n", t, sum);
	}
 
	return 0;
} 
