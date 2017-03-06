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
#include <algorithm>
#include <limits.h>
#define INF 1000000000
using namespace std;
 
int N, EXIT, T, E;
vector< vector< pair<int, int> > > G;
int dist[101][101];
 
void init()
{
	int i;
	int f, s, w;
 
	scanf("%d %d %d %d", &N, &EXIT, &T, &E);
	G.resize(N+1);
	for(i=0; i<E; i++)
	{
		scanf("%d %d %d", &f, &s, &w);
		G[f].push_back(make_pair(s, w));
	}
}
 
void floyd_warshall()
{
	int i, j, k;
 
	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
			dist[i][j]=INF;
 
	for(i=1; i<=N; i++)
	{
		dist[i][i]=0;
		for(j=0; j<G[i].size(); j++)
			dist[i][G[i][j].first]=G[i][j].second;
	}
 
	for(k=1; k<=N; k++)
		for(i=1; i<=N; i++)
			for(j=1; j<=N; j++)
				dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
}
 
int solve()
{
	int c=0, i;
 
	for(i=1; i<=N; i++)
		if(dist[i][EXIT]<=T)
			c++;
 
	return c;
}
int main()
{
	//freopen("input.txt","r",stdin);
 
	init();
	floyd_warshall();
	printf("%d\n", solve());
 
	return 0;
} 
