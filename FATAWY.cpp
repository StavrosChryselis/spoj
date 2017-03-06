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
#include <string>
#include <ctype.h>
#include <vector>
#include <string.h>
#include <algorithm>
 
#define gc() getchar()
 
using namespace std;
 
vector< string > STRS;
int N, TH;
 
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
 
inline void getstring(string &A)
{
	char c;
 
	A.clear();
 
	A.push_back('0');
 
	c = gc();
 
	while (isspace(c))
		c = gc();
 
	while (!isspace(c) && c != EOF)
	{
		A.push_back(c);
		c = gc();
	}
}
 
inline int LCS(string &A, string &B)
{
	int DP[15][15];
	int i, j;
 
	memset(DP, 0, sizeof(DP));
 
	for (i = 1; i < A.length(); i++)
		for (j = 1; j < B.length(); j++)
		{
			if (A[i] == B[j])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
 
	return DP[A.length() - 1][B.length() - 1];
}
 
inline void init()
{
	int i;
	string S;
 
	STRS.clear();
 
	scanf("%d %d", &N, &TH);
 
	for (i = 0; i < N; i++)
	{
		getstring(S);
		STRS.push_back(S);
	}
}
 
bool check(string &A, string &B)
{
	int lcs = LCS(A, B);
 
	if ((lcs * 1.0) / (A.length() - 1) >= TH / 100.0 && (lcs * 1.0) / (B.length() - 1) >= TH / 100.0)
		return 1;
 
	return 0;
}
 
inline int solve()
{
	int i, j;
	ufs g(N);
 
	for (i = 0; i < N - 1; i++)
		for (j = i + 1; j < N; j++)
			if (!g.is_same_set(i, j) && check(STRS[i], STRS[j]))
				g.union_sets(i, j);
 
	return g.size();
}
 
int main()
{
	int T, i;
 
	//freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	for (i = 1; i <= T; i++)
	{
		init();
		printf("Case #%d:\n%d\n", i, solve());
	}
 
	return 0;
} 
