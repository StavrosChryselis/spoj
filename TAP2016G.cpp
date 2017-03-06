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
#include <string.h>
#include <bitset>
#include <ctype.h>
#include <assert.h>
 
#define MAXN 100007
#define SHIFT 29
#define gc() getchar()
using namespace std;
 
struct node
{
	int index;
	struct node *ace;
	struct node *zero;
 
	node()
	{
		ace = zero = nullptr;
	}
};
 
inline bool eoi()
{
	char c = gc();
 
	while (isspace(c))
		c = gc();
 
	if (c == EOF)
		return 1;
 
	ungetc(c, stdin);
 
	return 0;
}
 
int N;
vector <vector< pair<int, int> > > G;
int val[MAXN];
struct node *tree;
 
inline void init()
{
	int i, f, s, w;
 
	scanf("%d", &N);
 
	G.clear();
	G.resize(N + 1);
	
	for (i = 0; i < N - 1; i++)
	{
		scanf("%d %d %d", &f, &s, &w);
		G[f].push_back(make_pair(s, w));
		G[s].push_back(make_pair(f, w));
	}	
	
	delete tree;
 
	tree = new struct node;
}
 
void insert(struct node **curr, int index, bitset<30> num, int pos)
{
	if (pos == -1)
	{
		(*curr)->index = index;
		return;
	}
 
	if (num[pos])
	{
		if ((*curr)->ace == nullptr)
			(*curr)->ace = new struct node;
 
		insert(&(*curr)->ace, index, num, pos - 1);
	}
 
	else
	{
		if ((*curr)->zero == nullptr)
			(*curr)->zero = new struct node;
 
		insert(&(*curr)->zero, index, num, pos - 1);
	}
}
 
int ffind(struct node *curr, bitset<30> num, int pos)
{
	if (pos == -1)
		return curr->index;
 
	if (num[pos])
	{
		if (curr->zero != nullptr)
			return ffind(curr->zero, num, pos - 1);
		else
			return ffind(curr->ace, num, pos - 1);
	}
 
	else
	{
		if (curr->ace != nullptr)
			return ffind(curr->ace, num, pos - 1);
		else
			return ffind(curr->zero, num, pos - 1);
	}
 
	return 0;
}
 
void destruct(struct node **curr)
{
	if ((*curr)->ace != nullptr)
	{
		destruct(&(*curr)->ace);
		delete (*curr)->ace;
	}
 
	if ((*curr)->zero != nullptr)
	{
		destruct(&(*curr)->zero);
		delete (*curr)->zero;
	}
}
 
void dfs(int curr, int fro, int v)
{
	val[curr] = v;
 
	for (int i = 0; i < G[curr].size(); i++)
		if(G[curr][i].first != fro)
			dfs(G[curr][i].first, curr, v ^ G[curr][i].second);
}
 
inline void solve()
{
	int i;
 
	for (i = 1; i <= N; i++)
	{
		bitset<30> temp(val[i]);
		insert(&tree, i, temp, 29);
	}
 
	for (i = 1; i <= N; i++)
	{
		bitset<30> temp(val[i]);
		printf("%d\n", val[i] ^ val[ffind(tree, temp, 29)]);
	}
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
 
	while (!eoi())
	{
		init();
		dfs(1, 1, 0);
		solve();
		destruct(&tree);
	}
	return 0;
} 
