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
#include <list>
#include <algorithm>
 
using namespace std;
 
vector< vector<int> > G;
list< pair<int, int> > Q;
vector<bool> V;
int N;
 
void init()
{
	int i;
	int from, to;
 
	scanf("%d", &N);
	
	G.resize(N+1);
	V.resize(N+1);
	for(i=0; i<N-1; i++)
	{
		scanf("%d %d", &from, &to);
		G[from].push_back(to);
		G[to].push_back(from);
	}
}
 
int BFS1()
{
	pair<int, int> mmax, curr;
	int i;
 
	Q.push_back(make_pair(0, 1));
 
	while(!Q.empty())
	{
		curr=Q.front();
		Q.pop_front();
 
		mmax=max(mmax,curr);
		V[curr.second]=1;
 
		for(i=0; i<G[curr.second].size(); i++)
			if(!V[G[curr.second][i]])
				Q.push_back(make_pair(curr.first+1, G[curr.second][i]));
	}
 
	return mmax.second;
}
 
int BFS2(int root)
{
	pair<int, int> mmax, curr;
	int i;
 
	Q.push_back(make_pair(0, root));
 
	while(!Q.empty())
	{
		curr=Q.front();
		Q.pop_front();
 
		mmax=max(mmax, curr);
		V[curr.second]=1;
 
		for(i=0; i<G[curr.second].size(); i++)
			if(!V[G[curr.second][i]])
				Q.push_back(make_pair(curr.first+1, G[curr.second][i]));
	}
 
	return mmax.first;
}
 
int main()
{
	int root;
 
	//freopen("input.txt","r",stdin);
 
	init();
	root=BFS1();
	V.clear();
	V.resize(N+1);
 
	printf("%d\n", BFS2(root));
 
	return 0;
} 
