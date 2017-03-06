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
#include <ctype.h>
#include <string>
#include <string.h>
 
#define MOD 100007
#define gc() getchar()
using namespace std;
 
inline void getstring(string &A)
{
	char c = gc();
 
	A.clear();
 
	while (isspace(c))
		c = gc();
 
	while (!isspace(c) && c != EOF)
	{
		A.push_back(c);
		c = gc();
	}
}
 
string S;
 
inline int solve()
{
	int rval = 0;
	int memo[26];
	int i, j;
 
	memset(memo, 0, sizeof(memo));
 
	j = 0;
 
	for (i = 0; i < S.size(); i++)
	{
		if (memo[S[i] - 'a'])
			while (memo[S[i] - 'a'])
			{
				memo[S[j] - 'a']--;
				j++;
			}
 
 		memo[S[i] - 'a']++;
 
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
		getstring(S);
		printf("Case %d: %d\n", i, solve());
	}
 
	return 0;
} 
