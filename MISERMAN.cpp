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
 
int board[105][105];
int N, M;
 
inline int min3(int a, int b, int c)
{
	return min(a, min(b, c));
}
 
int solve()
{
	int i, j;
	int sol;
 
	for(i=N-1; i>=2; i--)
	{
		board[i][1]+=min(board[i+1][1], board[i+1][2]);
		board[i][M]+=min(board[i+1][M], board[i+1][M-1]);
 
		for(j=2; j<=M-1; j++)
			board[i][j]+=min3(board[i+1][j-1], board[i+1][j], board[i+1][j+1]);
	}
 
	board[1][1]+=min(board[2][1], board[2][2]);
	board[1][M]+=min(board[2][M], board[2][M-1]);
	sol=min(board[1][1], board[1][M]);
 
	for(i=2; i<=M-1; i++)
	{
		board[1][i]+=min3(board[2][i-1], board[2][i], board[2][i+1]);
		sol=min(sol, board[1][i]);
	}
 
	return sol;
}
 
inline void init()
{
	int i, j;
 
	scanf("%d %d", &N, &M);
 
	for(i=1; i<=N; i++)
		for(j=1; j<=M; j++)
			scanf("%d", &board[i][j]);
}
 
int main()
{
	int T;
 
	//freopen("input.txt","r",stdin);
 
	init();
	printf("%d\n", solve());
 
	return 0;
}  
