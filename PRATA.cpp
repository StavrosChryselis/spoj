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
 
#define MAXN 4004010
using namespace std;
 
inline int get_pratas(int R, int M)
{
	double r = R, m = M;
 
	return floor((sqrt(r * r + 8 * r * M) - r) / (2 * r));
}
 
int A[57];
int N, P;
 
inline void init()
{
	int i;
 
	scanf("%d", &P);
	scanf("%d", &N);
 
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
}
 
inline int sum_pratas(int M)
{
	int sum = 0;
 
	for (int i = 0; i < N; i++)
		sum += get_pratas(A[i], M);
 
	return sum;
}
 
inline int solve()
{
	int hi = MAXN, lo = 0;
 
	while (lo != hi - 1)
	{
		int med = (lo + hi) / 2;
 
		if (sum_pratas(med) >= P)
			hi = med;
		else
			lo = med;
	}
 
	return hi;
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
