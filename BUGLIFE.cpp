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
#include <vector>
 
using namespace std;
 
int N, E;
 
vector< vector<int> > G;
int V[2010];
 
inline void init()
{
	int i, f, s;
 
	G.clear();
	memset(V, -1, sizeof(V));
 
	scanf("%d %d", &N, &E);
 
	G.resize(N+1);
 
	for(i=0; i<E; i++)
	{
		scanf("%d %d", &f, &s);
		G[f].push_back(s);
		G[s].push_back(f);
	}
}
 
bool dfs(int curr, int path)
{
	int i;
 
	if(V[curr] != -1)
	{
		if((path - V[curr])%2 != 0 )
			return 0;
		return 1;
	}
 
	V[curr] = path;
 
	for(i = 0; i < G[curr].size(); i++)
		if(!dfs(G[curr][i], path + 1))
			return 0;
 
	return 1;
}
 
inline bool solve()
{
	int i;
 
	for(i=1; i<=N; i++)
		if(V[i] == -1 && !dfs(i, 0))
			return 0;
	
	return 1;
}
 
int main()
{
	int T, i;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	for(i=1; i<=T; i++)
	{
		init();
		if(!solve())
			printf("Scenario #%d:\nSuspicious bugs found!\n", i);
		else
			printf("Scenario #%d:\nNo suspicious bugs found!\n", i);
	}
 
	return 0;
} 
