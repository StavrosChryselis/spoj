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
 
using namespace std;
 
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
			if(S[name].parent->name==name)
				return &S[name];
 
			S[name].parent=fs(S[name].parent->name);
			return S[name].parent;
		}
 
 
	public:
		ufs(int n)
		{
			int i;
			ssize=n;
			S.resize(ssize);
 
			for(i=0; i<S.size(); i++)
			{
				S[i].name=i;
				S[i].parent=&S[i];
				S[i].rank=0;
			}
		}
 
		
 
		void clear()
		{
			S.clear();
		}
 
		void make_set(int n)
		{
			clear();
 
			int i;
			ssize=n;
			S.resize(ssize);
 
			for(i=0; i<S.size(); i++)
			{
				S[i].name=i;
				S[i].parent=&S[i];
				S[i].rank=0;
			}
		}
 
		int find_set(int name)
		{
			return fs(name)->name;
		}
 
		bool is_same_set(int a, int b)
		{
			return fs(a)->name==fs(b)->name;
		}
 
		void union_sets(int a, int b)
		{
			set *f, *s;
 
			f=fs(a);
			s=fs(b);
 
			if(f->name==s->name)
				return;
 
			ssize--;
			if(f->rank==s->rank)
			{
				f->rank++;
				s->parent=f;
			}
	
			else if(f->rank > s->rank)
				s->parent=f;
	
			else
				f->parent=s;
		}
 
		int size()
		{
			return ssize;
		}
};
 
vector< vector<int> > T;
vector<int> ancestor;
vector<bool> color; //0-white, 1-black
vector< vector<int> > LCA;
vector<bool> has_parent;
int N, Q;
int root;
ufs S(1);
 
void TarjanOLCA(int u)
{
	int i, v;
 
	ancestor[u]=u;
 
	for(i=0; i<T[u].size(); i++)
	{
		v=T[u][i];
		TarjanOLCA(v);
		S.union_sets(u, v);
		ancestor[S.find_set(u)]=u;
	}
 
	color[u]=1;
 
	for(i=1; i<=N; i++)
		if(color[i])
		{
			LCA[u][i]=ancestor[S.find_set(i)];
			LCA[i][u]=LCA[u][i];
		}
}
 
inline void init()
{
	int i, num, M, j;
 
	scanf("%d", &N);
	T.clear();
	T.resize(N+1);
	ancestor.clear();
	ancestor.resize(N+1);
	color.clear();
	color.resize(N+1);
	S.make_set(N+1);
	LCA.clear();
	LCA.resize(N+1);
	has_parent.resize(N+1);
 
	for(i=0; i<LCA.size(); i++)
		LCA[i].resize(N+1);
 
	for(i=1; i<=N; i++)
	{
		scanf("%d", &M);
 
		for(j=0; j<M; j++)
		{
			scanf("%d", &num);
			has_parent[num]=1;
			T[i].push_back(num);
		}
	}
}
 
inline void find_root()
{
	int i;
 
	for(i=1; i<=N; i++)
		if(!has_parent[i])
		{
			root=i;
			return;
		}
}
 
int main()
{
	int T, i, j;
	int f, s;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	for(i=1; i<=T; i++)
	{
		init();
		find_root();
		TarjanOLCA(root);
		scanf("%d", &Q);
		printf("Case %d:\n", i);
		for(j=0; j<Q; j++)
		{
			scanf("%d %d", &f, &s);
			printf("%d\n", LCA[f][s]);
		}
	}
 
	return 0;
} 
