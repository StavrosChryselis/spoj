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
#include <algorithm>
 
using namespace std;
 
int V[2001];
int DP[2001][2001];
 
int main()
{
	int i, N, j, k;
	//freopen("input.txt","r",stdin);
	
	scanf("%d", &N);
 
	scanf("%d", &V[1]);
	DP[1][1]=V[1]*N;
 
	for(i=2; i<=N; i++)
	{
		scanf("%d", &V[i]);
		DP[i][i]=V[i]*N;
		DP[i-1][i]=min(V[i], V[i-1])*(N-1) + max(V[i], V[i-1])*N;
	}
	
	for(k=3; k<=N; k++)
		for(i=1; i<=N-k+1; i++)
		{
			j=i+k-1;
			DP[i][j]=max(V[i]*(N-(j-i)) + DP[i+1][j], V[j]*(N-(j-i)) + DP[i][j-1]);
		}
	
	printf("%d\n", DP[1][N]);
	return 0;
} 
