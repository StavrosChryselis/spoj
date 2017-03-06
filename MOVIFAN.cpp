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
#include <algorithm>
#include <vector>
#include <string.h>
 
#define MOD 1000000007
#define MAXN 300007
#define ll long long
using namespace std;
 
int dummy[MAXN];
ll ans[MAXN];
int N, L;
vector< pair<int, int> > A;
 
inline void init()
{
	int i;
 
	A.clear();
	memset(ans, 0, sizeof(ans));
 
	scanf("%d %d", &N, &L);
 
	for (i = 0; i < N; i++)
		scanf("%d", &dummy[i]);
 
	sort(dummy, dummy + N);
 
	for (i = 0; i < N; i++)
		A.push_back(make_pair(dummy[i], i));
 
	A.push_back(make_pair(MAXN * 2, N));
}
 
inline ll solve()
{
	vector< pair<int, int> >::iterator ii;
	int i;
 
	for (i = 0; i < N; i++)
	{
		ii = lower_bound(A.begin(), A.end(), make_pair(A[i].first + L, 0));
		ans[ii->second] += ans[A[i].second] * 2 + 1;
		ans[ii->second] %= MOD;
	}
 
	return ans[N] % MOD;
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
	int T;
 
	scanf("%d", &T);
 
	while (T--)
	{
		init();
		printf("%lld\n", solve());
	}
 
	return 0;
} 
