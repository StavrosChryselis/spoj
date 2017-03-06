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
#include <vector>
#include <string.h>
#include <algorithm>
#include <ctype.h>
 
#define gc() getchar_unlocked()
using namespace std;
 
vector<int>  DP[107][107];
int board[107][107];
bool V[107][107][507];
int N, M, K;
 
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
 
	//scanf("%d %d %d", &N, &M, &K);
	N = FAST_IO();
	M = FAST_IO();
	K = FAST_IO();
 
	memset(V, 0, sizeof(V));
 
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			//scanf("%d", &board[i][j]);
			board[i][j] = FAST_IO();
}
 
inline int solve()
{
	int i, j;
	vector<int>::iterator ii;
 
	DP[1][1].clear();
 
	if (board[1][1] <= K)
		DP[1][1].push_back(board[1][1]);
	else
		return -1;
 
	for (i = 2; i <= N; i++)
	{
		DP[i][1].clear();
		for (ii = DP[i - 1][1].begin(); ii != DP[i - 1][1].end(); ii++)
			if (*ii + board[i][1] <= K && !V[i][1][*ii])
			{
				V[i][1][*ii] = 1;
				DP[i][1].push_back(*ii + board[i][1]);
			}
	}
 
	for (i = 2; i <= M; i++)
	{
		DP[1][i].clear();
		for (ii = DP[1][i - 1].begin(); ii != DP[1][i - 1].end(); ii++)
			if (*ii + board[1][i] <= K && !V[1][i][*ii])
			{
				V[1][i][*ii] = 1;
				DP[1][i].push_back(*ii + board[1][i]);
			}
	}
 
	for (i = 2; i <= N; i++)
		for (j = 2; j <= M; j++)
		{
			DP[i][j].clear();
			for (ii = DP[i - 1][j - 1].begin(); ii != DP[i - 1][j - 1].end(); ii++)
				if (*ii + board[i][j] <= K && !V[i][j][*ii])
				{
					V[i][j][*ii] = 1;
					DP[i][j].push_back(*ii + board[i][j]);
				}
 
			for (ii = DP[i - 1][j].begin(); ii != DP[i - 1][j].end(); ii++)
				if (*ii + board[i][j] <= K && !V[i][j][*ii])
				{
					V[i][j][*ii] = 1;
					DP[i][j].push_back(*ii + board[i][j]);
				}
 
			for (ii = DP[i][j - 1].begin(); ii != DP[i][j - 1].end(); ii++)
				if (*ii + board[i][j] <= K && !V[i][j][*ii])
				{
					V[i][j][*ii] = 1;
					DP[i][j].push_back(*ii + board[i][j]);
				}
		}
 
	if (DP[N][M].empty())
		return -1;
 
	int MMAX = -1;
 
	for (ii = DP[N][M].begin(); ii != DP[N][M].end(); ii++)
		MMAX = max(MMAX, *ii);
 
	return MMAX;
}
 
int main()
{
	int T;
 
	//freopen("input.txt", "r", stdin);
 
	//scanf("%d", &T);
	T = FAST_IO();
 
	while (T--)
	{
		init();
		printf("%d\n", solve());
	}
 
	return 0;
} 
