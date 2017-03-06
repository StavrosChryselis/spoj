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
#include <bitset>
#include <vector>
#include <string.h>
 
using namespace std;
 
vector< bitset<100> > A, TC;
int N;
 
inline void init()
{
	int i, f, s;
 
	scanf("%d", &N);
 
	A.clear();
	A.resize(N);
 
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &f, &s);
		A[f][s] = 1;
	}
}
 
inline int solve()
{
	int i, j, k, rval = 0;
 
	TC = A;
 
	for (k = 0; k < N; k++)
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (!TC[i][j] && TC[i][k] && TC[k][j])
					TC[i][j] = 1;
 
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (!A[i][j] && TC[i][j])
				rval++;
 
	return rval;
}
 
int main()
{
	int T, t;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	for (t = 1; t <= T; t++)
	{
		init();
		printf("Case #%d: %d\n", t, solve());
	}
 
	return 0;
} 
