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
#include <ctype.h>
 
#define gc() getchar_unlocked()
#define MAXN 100000
#define MAXM 30
using namespace std;
 
int N, M;
int DP[MAXN + 7];
int steps[MAXM + 7];
 
inline int FAST_IO()
{
	char ch;
	int val = 0;
	ch = gc();
	while (isspace(ch) && ch != EOF)
		ch = gc();
	val = 0;
	while (isdigit(ch))
	{
		val = (val * 10) + (ch - '0');
		ch = gc();
	}
	return val;
}
 
inline void init()
{
	int i;
 
	N = FAST_IO();
	M = FAST_IO();
 
	for (i = 0; i < M; i++)
		steps[i] = FAST_IO();
}
 
inline int grundy(int pos)
{
	int i;
	bool a[50] = { 0 };
 
	for (i = 0; i < M; i++)
		if (steps[i] <= pos)
			a[DP[pos - steps[i]]] = 1;
 
	for (i = 0; i < 50; i++)
		if (!a[i])
			return i;
 
	return 0;
}
 
inline void calc_dp()
{
	int i;
 
	for (i = 1; i <= MAXN; i++)
		DP[i] = grundy(i);
}
 
inline bool solve()
{
	int num, rval = 0;
 
	while (N--)
	{
		num = FAST_IO();
		rval ^= DP[num];
	}
 
	return rval;
}
 
int main()
{
	int T;
 
//	freopen("input.txt", "r", stdin);
 
	T = FAST_IO();
 
	while (T--)
	{
		init();
		calc_dp();
		if (!solve())
			printf("Vinit\n");
		else
			printf("Ada\n");
	}
 
	return 0;
} 
