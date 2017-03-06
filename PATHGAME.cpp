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
#include <deque>
#include <string.h>
#include <vector>
 
#define gc() getchar()
 
using namespace std;
 
int V[3][57];
int board[4][57];
int N, blacks;
 
inline void init()
{
	int i;
	char c;
 
	memset(V, 0, sizeof(V));
	memset(board, 0, sizeof(board));
	blacks = 0;
 
	scanf("%d\n", &N);
 
	for (i = 1; i <= N; i++)
	{
		c = gc();
		if (c == '.')
			board[1][i] = 1;
		else
			blacks++;
	}
 
	gc();
 
	for (i = 1; i <= N; i++)
	{
		c = gc();
		if (c == '.')
			board[2][i] = 1;
		else
			blacks++;
	}
}
 
inline int BFS()
{
	deque< pair<int, pair<int, int> > >Q;
	pair<int, pair<int, int> >curr; //len, x, y
 
	if (board[1][1])
	{
		Q.push_back(make_pair(1, make_pair(1, 1)));
		V[1][1] = 1;
	}
 
	if (board[2][1])
	{
		Q.push_back(make_pair(1, make_pair(2, 1)));
		V[2][1] = 1;
	}
 
	while (!Q.empty())
	{
		curr = Q.front();
		Q.pop_front();
 
		if (curr.second.second == N)
			return curr.first;
 
		if (board[curr.second.first - 1][curr.second.second] && !V[curr.second.first - 1][curr.second.second])
		{
			V[curr.second.first - 1][curr.second.second] = 1;
			Q.push_back(make_pair(curr.first + 1, make_pair(curr.second.first - 1, curr.second.second)));
		}
 
		if (board[curr.second.first + 1][curr.second.second] && !V[curr.second.first + 1][curr.second.second])
		{
			V[curr.second.first + 1][curr.second.second] = 1;
			Q.push_back(make_pair(curr.first + 1, make_pair(curr.second.first + 1, curr.second.second)));
		}
 
		if (board[curr.second.first][curr.second.second + 1] && !V[curr.second.first][curr.second.second + 1])
		{
			V[curr.second.first][curr.second.second + 1] = 1;
			Q.push_back(make_pair(curr.first + 1, make_pair(curr.second.first, curr.second.second + 1)));
		}
	}
 
	return -1;
}
 
int main()
{
	int T;
 
	//freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	while (T--)
	{
		init();
		printf("%d\n", N * 2 - BFS() - blacks);
	}
 
	return 0;
} 
