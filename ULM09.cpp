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
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <ctype.h>
#define gc() getchar_unlocked()
 
using namespace std;
 
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
 
class ufs
{
private:
	struct set
	{
		int name;
		int rank;
		set *parent;
	};
	int ssize;
	vector<set> S;
 
	set *fs(int name)
	{
		if (S[name].parent->name == name)
			return &S[name];
 
		S[name].parent = fs(S[name].parent->name);
		return S[name].parent;
	}
 
 
public:
	ufs(int n)
	{
		int i;
		ssize = n;
		S.resize(ssize);
 
		for (i = 0; i<S.size(); i++)
		{
			S[i].name = i;
			S[i].parent = &S[i];
			S[i].rank = 0;
		}
	}
 
	int find_set(int name)
	{
		return fs(name)->name;
	}
 
	bool is_same_set(int a, int b)
	{
		return fs(a)->name == fs(b)->name;
	}
 
	void union_sets(int a, int b)
	{
		set *f, *s;
 
		f = fs(a);
		s = fs(b);
 
		if (f->name == s->name)
			return;
 
		ssize--;
		if (f->rank == s->rank)
		{
			f->rank++;
			s->parent = f;
		}
 
		else if (f->rank > s->rank)
			s->parent = f;
 
		else
			f->parent = s;
	}
 
	int size()
	{
		return ssize;
	}
};
 
vector< pair<int, pair<int, int> > > EDGES; //w, u, v
int N, E, total;
 
inline bool init()
{
	int i, f, s, w;
 
	//scanf("%d %d", &N, &E);
	N = FAST_IO();
	E = FAST_IO();
 
	if (N == 0 && E == 0)
		return 0;
 
	total = 0;
	EDGES.clear();
 
	for (i = 0; i < E; i++)
	{
		f = FAST_IO();
		s = FAST_IO();
		w = FAST_IO();
		//scanf("%d %d %d", &f, &s, &w);
		total += w;
		EDGES.push_back(make_pair(w, make_pair(f, s)));
	}
 
	return 1;
}
 
inline int solve()
{
	int i, c, ans = 0;
 
	ufs g(N);
 
	sort(EDGES.begin(), EDGES.end());
 
	for (i = 0, c = 0; i <EDGES.size() && c < N - 1; i++)
		if (!g.is_same_set(EDGES[i].second.first, EDGES[i].second.second))
		{
			c++;
			ans += EDGES[i].first;
			g.union_sets(EDGES[i].second.first, EDGES[i].second.second);
		}
 
	return total - ans;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
 
	while(init())
		printf("%d\n", solve());
 
	return 0;
} 
