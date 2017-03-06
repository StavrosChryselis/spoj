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
 
int A[31];
int dp[31][31], dp2[31][31];
int N;
int sum;
 
int main()
{
	int i, j, L, T;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while(T--)
	{
		sum=0;
		scanf("%d", &N);
 
		scanf("%d %d", &A[0], &A[1]);
		sum+=A[0];
		sum+=A[1];
		dp[0][0]=dp2[0][0]=A[0];
		dp[1][1]=dp2[1][1]=A[1];
		dp[0][1]=max(A[0], A[1]);
		dp2[0][1]=min(A[0], A[1]);
 
		for(i=2; i<N; i++)
		{
			scanf("%d", &A[i]);
			sum+=A[i];
			dp[i][i]=dp2[i][i]=A[i];
			dp[i-1][i]=max(A[i-1], A[i]);
			dp2[i-1][i]=min(A[i-1], A[i]);
		}
 
		for(L=3; L<=N; L++)
			for(i=0; i<=N-L; i++)
			{
				j=i+L-1;
				dp[i][j]=max(min(dp[i+1][j-1], dp[i+2][j])+A[i], min(dp[i+1][j-1], dp[i][j-2])+A[j]);
				dp2[i][j]=min(min(dp2[i+1][j-1], dp2[i+2][j])+A[i], min(dp2[i+1][j-1], dp2[i][j-2])+A[j]);
			}
		printf("%d %d\n", sum-min(dp2[1][N-1], dp2[0][N-2]), dp[0][N-1]);
	}
	
	return 0;
} 
