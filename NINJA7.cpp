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
 
#define MAXN 100007
 
using namespace std;
 
int A[MAXN];
int N;
 
inline void init()
{
	int i, num;
 
	scanf("%d", &N);
 
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
 
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		A[i] -= num;
	}
 
	sort(A, A + N);
}
 
inline int solve()
{
	int i, c = 0;
	long long sum = 0;
 
	for (i = N - 1; i >= 0; i--)
	{
		if (sum + A[i] >= 0)
		{
			sum += A[i];
			c++;
		}
 
		else
			return c;
	}
 
	return N;
}
 
int main()
{
	int T;
 
	//freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	while (T--)
	{
		init();
		printf("%d\n", solve());
	}
 
	return 0;
} 
