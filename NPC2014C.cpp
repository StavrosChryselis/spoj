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
#include <string.h>
 
#define MOD 1000000007
 
using namespace std;
 
long long DP[1024][128][3];		//0 chicken, 1 goat, 2 buffalo
int N, K;
 
int main()
{
	int i, currK;
	int T;
	long long sum;
 
	for(i=1; i<=1023; i++)
		DP[i][0][0] = 1;
 
	DP[1][1][1] = DP[1][1][2] = 1;
	
	for(i=2; i<= 1023; i++)
		for(currK = 1; currK <= min(127,i); currK++)
		{
			DP[i][currK][0] += DP[i-1][currK][0] + DP[i-1][currK][1] + DP[i-1][currK][2];
			DP[i][currK][1] += DP[i-1][currK-1][0] + DP[i-1][currK-1][2];
			DP[i][currK][2] += DP[i-1][currK-1][0] + DP[i-1][currK-1][1];
 
			while(DP[i][currK][0] >= MOD)
				DP[i][currK][0] -= MOD;
 
			while(DP[i][currK][1] >= MOD)
				DP[i][currK][1] -= MOD;
 
			while(DP[i][currK][2] >= MOD)
				DP[i][currK][2] -= MOD;
		}
 
	scanf("%d", &T);
 
	while(T--)
	{
		scanf("%d %d", &N, &K);
 
		if(N <= 2)
		{
			printf("1\n");
			continue;
		}
 
		N -= 2;
 
		if(K > N)
			K = N;
 
		sum = 0;
 
		for(i=0; i<=K; i++)
		{
			sum = sum + DP[N][i][0] + DP[N][i][1] + DP[N][i][2];
 
			while(sum >= MOD)
				sum -= MOD;
		}
 
		printf("%lld\n", sum);
	}
 
 
	return 0;
} 
