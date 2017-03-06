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
 
int DP[21][3];
int A[21][3];
 
int N;
 
inline void init()
{
	int i;
 
	scanf("%d", &N);
 
	for(i=1; i<=N; i++)
		scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
}
 
int main()
{
	int T, i;
 
	//freopen("input.txt","r",stdin);
	scanf("%d", &T);
 
	while(T--)
	{
		init();
 
		for(i=1; i<=N; i++)
		{
			DP[i][0]=A[i][0] + min(DP[i-1][1], DP[i-1][2]);
			DP[i][1]=A[i][1] + min(DP[i-1][0], DP[i-1][2]);
			DP[i][2]=A[i][2] + min(DP[i-1][0], DP[i-1][1]);
		}
 
		printf("%d\n", min(DP[N][0], min(DP[N][1], DP[N][2])));
	}
 
	return 0;
} 
