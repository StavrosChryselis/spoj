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
#include <deque>
#include <ctype.h>
 
#define gc() getchar_unlocked()
using namespace std;
 
unsigned long long fib[91], sum[91];
 
inline void getstring(deque<char> &A)
{
	char c = gc();
 
	while (isspace(c))
		c = gc();
 
	while (!isspace(c) && c != EOF)
	{
		A.push_front(c);
		c = gc();
	}
}
 
inline void pre()
{
	int i;
 
	fib[1] = fib[2] = 1;
	sum[1] = 1;
	sum[2] = 2;
 
	for (i = 3; i <= 90; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		sum[i] = fib[i] + sum[i - 1];
	}
}
 
inline unsigned long long solve()
{
	unsigned long long ans = 0;
	deque<char> S;
	int i;
 
	getstring(S);
 
	for (i = 0; i < S.size(); i++)
		if (S[i] == '1')
			ans += sum[i] + 1;
 
	return ans;
}
 
int main()
{
	int T, i;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	pre();
 
	for (i = 1; i <= T; i++)
		printf("Case %d: %llu\n", i, solve());
 
	return 0;
} 
