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
 
int A[2000014];
int N, K;
 
inline void init()
{
	int i;
 
	scanf("%d %d", &N, &K);
 
	for (i = 1; i <= K; i++)
		scanf("%d", &A[i]);
 
	sort(A + 1, A + K + 1);
 
	A[0] = -1;
 
	if (A[K] != N && A[K] != N - 1)
		A[++K] = N;
}
 
inline int solve()
{
	int i, sum, c = 0;
 
	for (i = 1; i <= K; i++)
	{
		sum = A[i] - A[i - 1];
		if (sum == 1)
			return 0;
 
		c += sum / 2;
	}
 
	return c;
}
 
int main()
{
	int T;
 
	scanf("%d", &T);
 
	while (T--)
	{
		init();
		printf("%d\n", solve());
	}
 
	return 0;
} 
