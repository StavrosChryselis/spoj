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
#include <deque>
#include <limits.h>
 
using namespace std;
 
int V[8][8];
deque< pair<int, pair<int, int> > > Q;
pair<int, int> start, finish;
int mmin=INT_MAX;
int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[] = {-2, -2, -1, 1, 2, 2, 1, -1};
 
inline void init_V()
{
	int i, j;
 
	for(i=0; i<8; i++)
		for(j=0; j<8; j++)
			V[i][j]=INT_MAX;
}
 
inline int calc_cost(pair<int, int> from, pair<int, int> to)
{
	return from.first * to.first + from.second * to.second;
}
 
inline bool outofrange(pair<int, int> pos)
{
	if(pos.first < 0 || pos.first > 7 || pos.second < 0 || pos.second > 7)
		return 1;
	return 0;
}
 
int solve()
{
	int i;
	pair<int, pair<int, int> > curr;
 
	Q.clear();
	mmin=INT_MAX;
	Q.push_back(make_pair(0, start));
 
	while(!Q.empty())
	{
		curr=Q.front();
		Q.pop_front();
 
		if(curr.second == finish)
		{
			mmin=min(mmin, curr.first);
			continue;
		}
 
		if(outofrange(curr.second))
			continue;
 
		if(V[curr.second.first][curr.second.second] <= curr.first)
			continue;
 
		V[curr.second.first][curr.second.second]=curr.first;
 
		for(i=0; i<8; i++)
			Q.push_back(make_pair(curr.first + calc_cost(curr.second, make_pair(curr.second.first + dx[i], curr.second.second + dy[i])), make_pair(curr.second.first + dx[i], curr.second.second + dy[i])));
	}
 
	if(mmin==INT_MAX)
		return -1;
	return mmin;
}
 
int main()
{
	//freopen("input.txt","r",stdin);
 
	while(!feof(stdin))
	{
		if(!scanf("%d %d %d %d\n", &start.first, &start.second, &finish.first, &finish.second))
			return 0;
		init_V();
		printf("%d\n", solve());
	}
 
	return 0;
}
 
