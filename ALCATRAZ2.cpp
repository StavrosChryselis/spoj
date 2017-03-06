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
#include <algorithm>
 
using namespace std;
 
const int N = 8;
const unsigned int MAXN = 1 << 8;
vector< pair<int, int> > E;
int A[N];
int M;
 
inline void init()
{
	int i;
	pair<int, int> t;
 
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
 
	scanf("%d", &M);
 
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &t.first, &t.second);
		t.first--;
		t.second--;
		E.push_back(t);
	}
}
 
inline bool test(unsigned int &bset, int pos)
{
	return bset & (1 << pos);
}
 
inline bool check(unsigned int &bset)
{
	int i;
 
	for (i = 0; i < M; i++)
		if (test(bset, E[i].first) && test(bset, E[i].second))
			return 0;
 
	return 1;
}
 
inline int sum(unsigned int &bset)
{
	int i;
	int rval = 0;
 
	for (i = 0; i < N; i++)
		if (test(bset, i))
			rval += A[i];
 
	return rval;
}
 
inline int solve()
{
	int rval = 0;
	unsigned int bset = 0;
 
	for (bset = 0; bset < MAXN; bset++)
		if (check(bset))
			rval = max(rval, sum(bset));
 
	return rval;
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
 
	init();
	printf("%d\n", solve());
 
	return 0;
} 
