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
#include <vector>
#include <ctype.h>
 
#define MAXN 100007
#define MAXK 57
#define gc() getchar_unlocked()
using namespace std;
 
int N, R, K;
pair<int, int> A[MAXN];
int DP[MAXN][MAXK];
int max_left[MAXN];
int SUM[MAXN];
 
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
	int i, j;
 
	N = FAST_IO();
	R = FAST_IO();
	K = FAST_IO();
 
 
	for (i = 1; i <= N; i++)
	{
		A[i].first = FAST_IO();
		A[i].second = FAST_IO();
	}
 
	sort(A, A + N + 1);
 
	for (i = 1; i <= N; i++)
		SUM[i] = SUM[i - 1] + A[i].second;
 
	max_left[1] = 1;
	i = 1;
 
	for (j = 2; j <= N; j++)
	{
		while (A[j].first - A[i].first > 2 * R)
			i++;
 
		max_left[j] = i;
	}
}
 
inline int solve()
{
	int i, j;
	int pos, val;
 
	for (i = 1; i <= K; i++)
		DP[1][i] = A[1].second;
 
	for (i = 2; i <= N; i++)
	{
		pos = max_left[i];
		val = SUM[i] - SUM[pos - 1];
 
		for (j = 1; j <= K; j++)
			DP[i][j] = max(DP[i - 1][j], val + DP[pos - 1][j - 1]);
		
	}
 
	return DP[N][K];
}
 
int main()
{
	int T, t;
 
//	freopen("input.txt", "r", stdin);
 
	T = FAST_IO();
 
	for (t = 1; t <= T; t++)
	{
		init();
		printf("Case %d: %d\n", t, solve());
	}
 
	return 0;
} 
