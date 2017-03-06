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
 
#define MOD 1000000007
#define gc() getchar()
using namespace std;
 
long long memo[1024][1024];
int N;
string S;
 
inline void getstring(string &A)
{
	char c = gc();
 
	A.clear();
 
	A.push_back('0');
 
	while (isspace(c))
		c = gc();
 
	while (!isspace(c) && c != EOF)
	{
		A.push_back(c);
		c = gc();
	}
}
 
inline void init()
{
	getstring(S);
	memset(memo, -1, sizeof(memo));
	N = S.size();
}
 
long long f(int pos, int open)
{
	int i;
	long long ans = 0;
 
	if (memo[pos][open] != -1)
		return memo[pos][open];
 
	if (!open)
		ans++;
 
	for (i = pos + 1; i < N && S[i] != '('; i++);
 
	if (i < N)
		ans += f(i, open + 1);
 
	if (ans >= MOD)
		ans -= MOD;
 
	if (open)
	{
		for (i = pos + 1; i < N && S[i] != ')'; i++);
 
		if (i < N)
			ans += f(i, open - 1);
	}
	
	if (ans >= MOD)
		ans -= MOD;
 
	memo[pos][open] = ans;
 
	return ans;
}
 
int main()
{
	int T;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	while (T--)
	{
		init();
		printf("%lld\n", f(0, 0));
	}
 
	return 0;
} 
