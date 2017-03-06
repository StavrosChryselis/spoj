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
 
long long A[100007], B[100007];
int N;
 
inline void init()
{
	int i;
 
	scanf("%d", &N);
 
	for (i = 0; i < N; i++)
		scanf("%lld", &A[i]);
 
	for (i = 0; i < N; i++)
		scanf("%lld", &B[i]);
 
}
 
inline bool solve()
{
	int i;
	long long prev;
 
	prev = min(A[0], B[0]);
 
	for (i = 1; i < N; i++)
	{
		if (max(A[i], B[i]) < prev)
			return 0;
 
		if (min(A[i], B[i]) < prev)
			prev = max(A[i], B[i]);
		else
			prev = min(A[i], B[i]);
	}
 
	return 1;
 
}
 
int main()
{
	int T;
 
	scanf("%d", &T);
 
	while (T--)
	{
		init();
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}
 
	return 0;
} 
