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
#include <string.h>
 
using namespace std;
 
class ufs
{
	private:
		struct set
		{
			int name;
			int rank;
			int money;
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
			S.resize(ssize + 1);
 
			for (i = 1; i<S.size(); i++)
			{
				S[i].name = i;
				S[i].parent = &S[i];
				S[i].rank = 0;
				scanf("%d", &S[i].money);
			}
		}
 
		int find_set(int name)
		{
			return fs(name)->name;
		}
 
		int get_money(int name)
		{
			return fs(name)->money;
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
				f->money += s->money;
			}
 
			else if (f->rank > s->rank)
			{
				s->parent = f;
				f->money += s->money;
			}
 
			else
			{
				f->parent = s;
				s->money += f->money;
			}
		}
 
		int size()
		{
			return ssize;
		}
};
 
ufs *DSU;
int N, M;
bool V[1024];
 
inline void init()
{
	int i, f, s;
 
	delete DSU;
 
	memset(V, 0, sizeof(V));
 
	scanf("%d %d", &N, &M);
 
	DSU = new ufs(N);
 
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &f, &s);
		DSU->union_sets(f, s);
	}
}
 
inline void solve(int c)
{
	int i, t;
	vector<int> val;
 
	for (i = 1; i <= N; i++)
	{
		t = DSU->find_set(i);
		if (!V[t])
		{
			V[t] = 1;
			val.push_back(DSU->get_money(t));
		}
	}
 
	printf("Case %d: %d\n", c, val.size());
 
	sort(val.begin(), val.end());
	
	for (i = 0; i < val.size(); i++)
		printf("%d ", val[i]);
 
	putchar('\n');
}
 
int main()
{
	int T, i;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	for (i = 1; i <= T; i++)
	{
		init();
		solve(i);
	}
 
	return 0;
} 
