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
 
#define pc(x) putchar(x)
using namespace std;
 
int N, MAX;
char board[37][77];
int A[77];
 
inline void print(int curr)
{
	int i;
 
	for (i = 0; i < N; i++)
	{
		if (board[curr][i])
			pc(board[curr][i]);
		else
			pc(' ');
	}
 
	pc('\n');
}
 
inline bool init()
{
	int i;
 
	scanf("%d", &N);
 
	if (N == -1)
		return 0;
 
	memset(board, 0, sizeof(board));
 
	for (i = 0; i <= N; i++)
		scanf("%d", &A[i]);
	
 
	return 1;
}
 
inline void solve()
{
	int i, curr;
	bool pos; //0 down, 1 up
 
	curr = A[0];
	pos = 0;
	MAX = 0;
 
	for (i = 1; i <= N; i++)
	{
		if (A[i] > A[i - 1])
		{
			if (!pos)
			{
				board[curr][i - 1] = '/';
				pos = 1;
			}
 
			else
			{
				curr++;
				board[curr][i - 1] = '/';
			}
		}
 
		else if (A[i] < A[i - 1])
		{
			if (!pos)
			{
				curr--;
				board[curr][i - 1] = '\\';
			}
 
			else
			{
				board[curr][i - 1] = '\\';
				pos = 0;
			}
		}
 
		else
		{
			if (!pos)
				board[curr][i - 1] = '_';
			else
			{
				curr++;
				board[curr][i - 1] = '_';
				pos = 0;
			}
		}
 
		MAX = max(MAX, curr);
	}
 
	for (i = MAX; i >= 0; i--)
		print(i);
	printf("***\n");
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
 
	while (init())
		solve();
 
	return 0;
} 
