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
 
inline int max3(int a, int b, int c)
{
	return max(a, max(b, c));
}
 
int solve()
{
	int i, j;
	int sol;
 
	for(i=N-1; i>=2; i--)
	{
		board[i][1]+=max(board[i+1][1], board[i+1][2]);
		board[i][M]+=max(board[i+1][M], board[i+1][M-1]);
 
		for(j=2; j<=M-1; j++)
			board[i][j]+=max3(board[i+1][j-1], board[i+1][j], board[i+1][j+1]);
	}
 
	board[1][1]+=max(board[2][1], board[2][2]);
	board[1][M]+=max(board[2][M], board[2][M-1]);
	sol=max(board[1][1], board[1][M]);
 
	for(i=2; i<=M-1; i++)
	{
		board[1][i]+=max3(board[2][i-1], board[2][i], board[2][i+1]);
		sol=max(sol, board[1][i]);
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
 
	scanf("%d", &T);
 
	while(T--)
	{
		init();
		printf("%d\n", solve());
	}
 
	return 0;
} 
