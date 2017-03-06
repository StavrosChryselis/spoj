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
#include <ctype.h>
 
#define gc() getchar_unlocked()
#define MOD 1000000007
 
using namespace std;
 
int N, E;
 
inline int FAST_IO()
{
    char ch;
    int val=0;
    ch=gc();
    while(isspace(ch) && ch!=EOF)
            ch=gc();
    val=0;
    while(isdigit(ch))
    {
        val=(val*10)+(ch-'0');
        ch=gc();
    }
    return val;
}
 
inline int solve()
{
	int i, j, f, s;
 
	N = FAST_IO();
	E = FAST_IO();
	//scanf("%d %d", &N, &E);
 
	vector< vector<int> > G(N+1);
	vector<int> DP(N+1);
 
	for(i = 0; i < E; i++)
	{
		f = FAST_IO();
		s = FAST_IO();
		//scanf("%d %d", &f, &s);
		G[f].push_back(s);
	}
 
	DP[1] = 1;
 
	for(i = 1; i < N; i++)
		for(j = 0; j < G[i].size(); j++)
		{
			DP[G[i][j]] += DP[i];
			while(DP[G[i][j]] >= MOD)
				DP[G[i][j]] -= MOD;
		}
 
	while(DP[N] >= MOD)
		DP[N] -= MOD;
 
	return DP[N];
}
 
int main()
{
	int T, i;
 
	//freopen("input.txt","r",stdin);
 
	T = FAST_IO();
	//scanf("%d", &T);
 
	for(i = 1; i <= T; i++)
		printf("Case %d: %d\n", i, solve());
 
	return 0;
} 
