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
#include <string>
#define gc() getchar_unlocked()
 
using namespace std;
 
int dx[]={-1, -1, -1,  0, 0,  1, 1, 1};
int dy[]={-1,  0,  1, -1, 1, -1, 0, 1};
char board[128][128];
bool V[128][128];
int R, C;
string S = "ALLIZZWELL";
 
inline void init()
{
	int i, j;
 
	scanf("%d %d\n", &R, &C);
	memset(board, 0, sizeof(board));
 
	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
			board[i][j] = gc();
		gc();
	}
}
 
inline int check(int pos, int x, int y)
{
	if(pos == S.length())
		return 1;
 
	if(x<0 || y<0 || x>=R || y>=C)
		return 0;
 
	if(board[x][y] != S[pos] || V[x][y])
		return 0;
 
	return -1;
}
 
int solve(int x, int y, int pos)
{
	int i;
 
	int temp = check(pos, x, y);
 
	if(temp == 0)
		return 0;
 
	if(temp == 1)
		return 1;
 
	V[x][y] = 1;
 
	for(i=0; i<8; i++)
		if(solve(x+dx[i], y+dy[i], pos+1))
			return 1;
 
	V[x][y] = 0;
	return 0;
}
 
inline bool solvee()
{
	int i, j;
 
	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
		{
			memset(V, 0, sizeof(V));
			if(solve(i, j, 0))
				return 1;
		}
	return 0;
}
 
int main()
{
	int T;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while(T--)
	{
		init();
		if(solvee())
			printf("YES\n");
		else
			printf("NO\n");
	}
 
	return 0;
} 
