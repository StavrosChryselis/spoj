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
#include <ctype.h>
 
#define MOD 1000000007
#define gc() getchar_unlocked()
 
using namespace std;
 
vector< vector< int > > TREE;
int BASE[100007], STEP[100007];
bool V[100007];
int N, Q;
 
inline int FAST_IO()
{
	char ch;
	int val = 0;
	ch = gc();
	while (isspace(ch) && ch != EOF)
		ch = gc();
	val = 0;
	while (isdigit(ch))
	{
		val = (val * 10) + (ch - '0');
		ch = gc();
	}
	return val;
}
 
inline void init()
{
	int i, f, s, u, base, step;
 
	//scanf("%d", &N);
	N = FAST_IO();
 
	TREE.resize(N + 1);
 
	for (i = 0; i < N - 1; i++)
	{
		//scanf("%d %d", &f, &s);
		f = FAST_IO();
		s = FAST_IO();
 
		TREE[f].push_back(s);
		TREE[s].push_back(f);
	}
 
	//scanf("%d", &Q);
	Q = FAST_IO();
 
	for (i = 0; i < Q; i++)
	{
		//scanf("%d %d %d", &u, &base, &step);
		u = FAST_IO();
		base = FAST_IO();
		step = FAST_IO();
 
		BASE[u] += base;
		if (BASE[u] >= MOD)
			BASE[u] -= MOD;
		STEP[u] += step;
		if (STEP[u] >= MOD)
			STEP[u] -= MOD;
	}
}
 
inline void BFS()
{
	deque< pair<int, int> > Q; //node, parent
	pair<int, int> curr;
	int i;
 
	V[1] = 1;
	Q.push_back(make_pair(1, 0));
 
	while (!Q.empty())
	{
		curr = Q.front();
		Q.pop_front();
 
		STEP[curr.first] += STEP[curr.second];
		if (STEP[curr.first] >= MOD)
			STEP[curr.first] -= MOD;
 
		BASE[curr.first] += BASE[curr.second];
		if (BASE[curr.first] >= MOD)
			BASE[curr.first] -= MOD;
 
		BASE[curr.first] += STEP[curr.second];
		if (BASE[curr.first] >= MOD)
			BASE[curr.first] -= MOD;
 
		for (i = 0; i < TREE[curr.first].size(); i++)
			if (!V[TREE[curr.first][i]])
			{
				V[TREE[curr.first][i]] = 1;
				Q.push_back(make_pair(TREE[curr.first][i], curr.first));
			}
	}
}
 
inline void print()
{
	int i;
 
	for (i = 1; i <= N; i++)
		printf("%d\n", BASE[i]);
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
 
	init();
	BFS();
	print();
 
	return 0;
} 
