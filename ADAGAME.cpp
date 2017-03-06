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
 
#define gc() getchar()
using namespace std;
 
short a, b, c, d;
int memo[10][10][10][10][107];	//0 = ada wins
int N;
 
inline void init()
{
	a = gc() - '0';
	b = gc() - '0';
	c = gc() - '0';
	d = gc() - '0';
 
	scanf("%d\n", &N);
 
	memset(memo, -1, sizeof(memo));
}
 
inline int inc(int num)
{
	if (num != 9)
		return num + 1;
 
	return 0;
}
 
bool solve(int aa, int bb, int cc, int dd, int n, bool player) //0 = ada, 1 = vinit
{
	if (memo[aa][bb][cc][dd][n] != -1)
		return memo[aa][bb][cc][dd][n];
 
	if (!n)
	{
		if (aa * 1000 + bb * 100 + cc * 10 + d > a * 1000 + b * 100 + c * 10 + d)
		{
			memo[aa][bb][cc][dd][0] = 0;
			return 0;
		}
 
		else
		{
			memo[aa][bb][cc][dd][0] = 1;
			return 1;
		}
	}
 
	if (!player) // an pezei o ada
	{
		if (!solve(inc(aa), bb, cc, dd, n - 1, !player) || !solve(aa, inc(bb), cc, dd, n - 1, !player) || !solve(aa, bb, inc(cc), dd, n - 1, !player) || !solve(aa, bb, cc, inc(dd), n - 1, !player))
		{
			memo[aa][bb][cc][dd][n] = 0;
			return 0;
		}
 
		else
		{
			memo[aa][bb][cc][dd][n] = 1;
			return 1;
		}
	}
 
	else	//an pezei o vinit
	{
		if (solve(inc(aa), bb, cc, dd, n - 1, !player) || solve(aa, inc(bb), cc, dd, n - 1, !player) || solve(aa, bb, inc(cc), dd, n - 1, !player) || solve(aa, bb, cc, inc(dd), n - 1, !player))
		{
			memo[aa][bb][cc][dd][n] = 1;
			return 1;
		}
 
		else
		{
			memo[aa][bb][cc][dd][n] = 0;
			return 0;
		}
	}
}
 
int main()
{
	int T;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d\n", &T);
 
	while (T--)
	{
		init();
		if (!solve(a, b, c, d, N, 0))
			printf("Ada\n");
		else
			printf("Vinit\n");
	}
 
	return 0;
} 
