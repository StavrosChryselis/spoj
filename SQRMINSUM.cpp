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
#include <math.h>
#include <algorithm>
 
using namespace std;
 
int N, K;
int A[10007];
 
inline void init()
{
	scanf("%d %d", &N, &K);
 
	for (int i = 1; i <= N; i++)
		A[i] = 1;
}
 
inline int solve()
{
	int i, sum = 0, t;
	
	for (i = N; i > 1; i--)
	{
		t = min(A[i], K);
 
		A[i] -= t;
		A[(int)sqrt(i)] += t;
		K -= t;
 
		if (!K)
			break;
	}
 
	for (i = 1; i <= N; i++)
		sum += A[i] * i;
 
	return sum;
}
 
int main()
{
	int T;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	while (T--)
	{
		init();
		printf("%d\n", solve());
	}
 
	return 0;
} 
