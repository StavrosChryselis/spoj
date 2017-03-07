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

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAXN 10007
using namespace std;

vector < vector<int> > G(MAXN);
bool V[MAXN];
int N, M;

inline void init()
{
	int i, f, s;

	cin >> N >> M;

	for (i = 0; i < M; i++)
	{
		cin >> f >> s;
		G[f].push_back(s);
	}

}

int dfs(int curr)
{
	int i;
	int rval = 1;

	for (i = 0; i < G[curr].size(); i++)
		if (!V[G[curr][i]])
		{
			V[G[curr][i]] = 1;
			rval += dfs(G[curr][i]);
		}

	return rval;
}

inline int solve()
{
	int rval = 0;
	int i;

	for (i = 1; i <= N; i++)
	{
		memset(V, 0, sizeof(V));
		V[i] = 1;
		rval = max(rval, dfs(i));
	}

	return rval;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	init();
	cout << solve() << "\n";

	return 0;
}
