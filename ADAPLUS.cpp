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
#include <algorithm>
#include <string.h>
 
#define gc() getchar()
#define MAXN 2048
using namespace std;
 
inline char next_char()
{
	char c = gc();
 
	while (isspace(c))
		c = gc();
 
	return c;
}
 
char board[MAXN][MAXN];
int maxleft[MAXN][MAXN];
int maxright[MAXN][MAXN];
int maxup[MAXN][MAXN];
int maxdown[MAXN][MAXN];
 
int N;
 
inline void init()
{
	int i, j;
 
	scanf("%d", &N);
 
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			board[i][j] = next_char();
 
	memset(maxleft, 0, sizeof(maxleft));
	memset(maxright, 0, sizeof(maxright));
	memset(maxdown, 0, sizeof(maxdown));
	memset(maxup, 0, sizeof(maxup));
 
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
		{
			if (board[i][j] == '#')
				maxleft[i][j] = maxleft[i][j - 1] + 1;
			else
				maxleft[i][j] = 0;
		}
 
	for (i = 1; i <= N; i++)
		for (j = N; j >= 1; j--)
		{
			if (board[i][j] == '#')
				maxright[i][j] = maxright[i][j + 1] + 1;
			else
				maxright[i][j] = 0;
		}
 
	for (j = 1; j <= N; j++)
		for (i = 1; i <= N; i++)
		{
			if (board[i][j] == '#')
				maxup[i][j] = maxup[i - 1][j] + 1;
			else
				maxup[i][j] = 0;
		}
 
	for (j = 1; j <= N; j++)
		for (i = N; i >= 1; i--)
		{
			if (board[i][j] == '#')
				maxdown[i][j] = maxdown[i + 1][j] + 1;
			else
				maxdown[i][j] = 0;
		}
}
 
inline int solve()
{
	int ans = 0;
	int i, j;
 
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			if(board[i][j] == '#')
				ans = max(ans, 1 + min(min(maxleft[i][j - 1], maxright[i][j + 1]), min(maxup[i - 1][j], maxdown[i + 1][j])));
 
	return ans;
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
