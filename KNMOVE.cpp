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
 
using namespace std;
 
int moves[1007][1007];
int dx[] = { -2, -2, 2, 2, 1, 1, -1, -1 };
int dy[] = { -1, 1, -1, 1, -2, 2, -2, 2 };
 
inline bool check(int x, int y)
{
	if (x < 1 || y < 1 || x > 1000 || y > 1000 || moves[x][y] != -1)
		return 0;
 
	return 1;
}
 
inline void init()
{
	int i;
	deque < pair<int, pair<int, int> > > Q;
	pair<int, pair<int, int> > curr;
 
	memset(moves, -1, sizeof(moves));
	moves[1][1] = 0;
 
 
	Q.push_back(make_pair(0, make_pair(1, 1)));
 
	while (!Q.empty())
	{
		curr = Q.front();
		Q.pop_front();
 
		for (i = 0; i < 8; i++)
			if (check(curr.second.first + dx[i], curr.second.second + dy[i]))
			{
				moves[curr.second.first + dx[i]][curr.second.second + dy[i]] = curr.first + 1;
				Q.push_back(make_pair(curr.first + 1, make_pair(curr.second.first + dx[i], curr.second.second + dy[i])));
			}
	}
}
 
int main()
{
	int T, x, y;
 
	init();
 
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%d %d", &x, &y);
		printf("%d\n", moves[x][y]);
	}
 
	return 0;
} 
