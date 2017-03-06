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
#include <string.h>
 
#define MOD 100007
#define MAXN 500007
#define MAXM 1000007
using namespace std;
 
int memo[MAXM];
int N, M;
int S[MAXN];
 
inline void init()
{
	int i;
 
	scanf("%d %d", &N, &M);
 
	for (i = 0; i < N; i++)
		scanf("%d", &S[i]);
}
 
inline int solve()
{
	int rval = 0;
	int i, j;
 
	memset(memo, 0, sizeof(memo));
 
	j = 0;
 
	for (i = 0; i < N; i++)
	{
		if (memo[S[i]])
			while (memo[S[i]])
			{
				memo[S[j]]--;
				j++;
			}
 
		memo[S[i]]++;
 
		int n = i - j + 1;
 
		rval += (n * (1 + n)) / 2;
		rval %= MOD;
	}
 
	return rval;
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
 
	int T, i;
 
	scanf("%d", &T);
 
	for (i = 1; i <= T; i++)
	{
		init();
		printf("Case %d: %d\n", i, solve());
	}
 
	return 0;
} 
