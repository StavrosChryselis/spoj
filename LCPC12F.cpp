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
 
using namespace std;
 
int N, X;
long long sum;
long long DP[4096];
 
inline void init()
{
	scanf("%d %d", &X, &N);
	sum = 0;
	memset(DP, 0, sizeof(DP));
}
 
int main()
{
	int T, i, j, num;
 
	scanf("%d", &T);
 
	for(i = 1; i <= T; i++)
	{
		init();
 
		for(j = 0; j < N; j++)
		{
			scanf("%d", &num);
			if(X < num)
				continue;
			sum += DP[X-num];
			DP[num]++;
		}
 
		printf("%d. %lld\n", i, sum);
	}
 
	return 0;
} 
