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
#include <limits.h>
#include <vector>
#include <unordered_map>
#define gc() getchar_unlocked()
 
using namespace std;
 
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int grid[183][183];
int dist[183][183];
int N, M;
deque< pair<int, int> > Q;
unordered_map< int, unordered_map<int, bool> > V;
 
inline void init()
{
	int i, j;
	char c;
 
	Q.clear();
	V.clear();
 
	scanf("%d %d\n", &N, &M);
 
	for(i=1; i<=N; i++)
	{
		for(j=1; j<=M; j++)
		{
			c = gc();
			grid[i][j] = c -'0';
 
			if(grid[i][j])
			{
				dist[i][j] = 0;
				Q.push_back(make_pair(i, j));
				V[i][j] = 1;
			}
			else
				dist[i][j] = INT_MAX;
		}
		gc();
	}
}
 
inline bool in_range(int x, int y)
{
	if(x < 1 || x > N || y < 1 || y > M)
		return 0;
	return 1;
}
 
void bfs()
{
	int x, y, i;
 
	while(!Q.empty())
	{
		x = Q.front().first;
		y = Q.front().second;
		Q.pop_front();
 
		for(i=0; i<4; i++)
			if(in_range(x + dx[i], y + dy[i]))
			{
				if(V.find(x + dx[i])==V.end())
				{
					dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
					V[x + dx[i]][y + dy[i]] = 1;
					Q.push_back(make_pair(x + dx[i], y + dy[i]));
				}
				else if(V[x + dx[i]].find(y + dy[i]) == V[x + dx[i]].end())
				{
					dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
					V[x + dx[i]][y + dy[i]] = 1;
					Q.push_back(make_pair(x + dx[i], y + dy[i]));
				}
			}
 
	}
}
 
int main()
{
	int T, i, j;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d\n", &T);
 
	while(T--)
	{
		init();
		bfs();
 
		for(i = 1; i<=N; i++)
		{
			for(j = 1; j<=M; j++)
				printf("%d ", dist[i][j]);
			putchar('\n');
		}
	}
	return 0;
} 
