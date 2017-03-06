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
#include <math.h>
#include <vector>
#define max(a,b) ((a>b)?a:b)
 
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
 
 
struct point
{
	int x;
	int y;
};
 
struct segment
{
	struct point begin;
	struct point end;
};
 
int ABbegin, ABend, BAbegin, BAend;
int N, M;
vector<struct segment> ALL;
 
inline int CCW(struct point p1, struct point p2, struct point p3)
{
	float res=(p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
	
	if(res>0)
		return 1;
	else if(res<0)
		return -1;
	else
		return 2;
}
 
inline bool same_point(struct segment A, struct segment B)
{
	if(A.begin.x == B.begin.x && A.begin.y == B.begin.y)
		return 1;
	if(A.end.x == B.begin.x && A.end.y == B.begin.y)
		return 1;
	if(A.begin.x == B.end.x && A.begin.y == B.end.y)
		return 1;
	if(A.end.x == B.end.x && A.end.y == B.end.y)
		return 1;
	return 0;
}
 
inline bool crosswise()
{
	if(ABbegin + ABend==0)
		if(BAbegin +BAend==0)
			return 1;
	return 0;
}
 
inline bool intersect_at_ends()
{
	if(ABbegin + ABend==0)
		if(BAbegin == 2 || BAend == 2)
			return 1;
 
	if(BAbegin + BAend==0)
		if(ABbegin == 2 || ABend == 2)
			return 1;
 
	return 0;
}
 
inline double distancee(struct point A, struct point B)
{
	return sqrt( pow((float)A.x-B.x, 2) + pow((float)A.y-B.y, 2));
}
 
int extended(struct segment A, struct segment B)
{
	double dist=0, distA=0, distB=0;
 
	if(ABbegin == 2 && ABend == 2 )
	{
		dist=distancee(A.begin, B.begin);
		dist=max(dist, distancee(A.begin, B.end));
		dist=max(dist, distancee(A.end, B.begin));
		dist=max(dist, distancee(A.end, B.end));
 
		distA=distancee(A.begin, A.end);
		distB=distancee(B.begin, B.end);
 
		if(dist<=distA + distB)
			return 1;
	}
 
	return 0;
}
 
inline bool intersect(struct segment A, struct segment B)
{
	ABbegin=CCW(A.begin, A.end, B.begin);
	ABend=CCW(A.begin, A.end, B.end);
	BAbegin=CCW(B.begin, B.end, A.begin);
	BAend=CCW(B.begin, B.end, A.end);
 
	if(same_point(A, B))
		return 1;
 
	if(crosswise())
		return 1;
 
	if(intersect_at_ends())
		return 1;
 
	if(extended(A, B))
		return 1;
 
	return 0;
}
 
void init()
{
	int i, j;
	int A, B;
	struct segment temp;
 
	scanf("%d %d", &N, &M);
 
	ALL.clear();
	ALL.push_back(temp);
 
	for(i=0; i<N; i++)
	{
		scanf("%d %d %d %d", &temp.begin.x, &temp.begin.y, &temp.end.x, &temp.end.y);
		ALL.push_back(temp);
	}
 
	ufs g(N+1);
 
	for(i=1; i<N; i++)
		for(j=i+1; j<=N; j++)
			if(intersect(ALL[i], ALL[j]))
				g.union_sets(i, j);
 
	for(i=0; i<M; i++)
	{
		scanf("%d %d", &A, &B);
		if(g.is_same_set(A, B))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
 
int main()
{
	int T;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while(T--)
		init();
 
	return 0;
} 
