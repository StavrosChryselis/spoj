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
#include <vector>
#include <string.h>
#include <limits.h>
 
#define gc() getchar()
using namespace std;
 
int N, M;
char board[1024][1024];
int dist[1024][1024];
bool V[1024][1024];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
inline void init()
{
	int i, j;
 
	memset(V, 1, sizeof(V));
 
	scanf("%d %d\n", &N, &M);
 
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			board[i][j] = gc();
			V[i][j] = 0;
			dist[i][j] = INT_MAX;
		}
		gc();
	}
}
 
 
inline int solve()
{
	int i, x, y;
	deque< pair<int, pair<int, int> > > Q;
	pair<int, pair<int, int> > curr;
 
	Q.push_back(make_pair(0, make_pair(1, 1)));
	dist[1][1] = 0;
 
	while (!Q.empty())
	{
		curr = Q.front();
		Q.pop_front();
		x = curr.second.first;
		y = curr.second.second;
		V[x][y] = 1;
		if (x == N && y == M)
			return dist[N][M];
 
		for (i = 0; i < 4; i++)
			if (!V[x + dx[i]][y + dy[i]])
			{
				if (board[x][y] == board[x + dx[i]][y + dy[i]] && dist[x + dx[i]][y + dy[i]] > curr.first)
				{
					dist[x + dx[i]][y + dy[i]] = curr.first;
					Q.push_front(make_pair(curr.first, make_pair(x + dx[i], y + dy[i])));
				}
				else if (board[x][y] != board[x + dx[i]][y + dy[i]] && dist[x + dx[i]][y + dy[i]] > curr.first + 1)
				{
					dist[x + dx[i]][y + dy[i]] = curr.first + 1;
					Q.push_back(make_pair(curr.first + 1, make_pair(x + dx[i], y + dy[i])));
				}
			}
	}
 
	return -1;
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
