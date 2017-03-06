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
#include <stdlib.h>
 
#define gc() getchar()
#define MAXN 1000000
using namespace std;
 
const long long MOD = 1000000007;
 
long long fact[1000007];
long long N, A, B, D;
 
inline long long modpow(long long base, long long exp, long long modulus) 
{
	long long result = 1;
 
	base %= modulus;
 
	while (exp > 0) 
	{
		if (exp & 1) 
			result = (result * base) % modulus;
 
		base = (base * base) % modulus;
		exp >>= 1;
	}
 
	return result;
}
 
inline bool finish()
{
	char c = gc();
 
	while (isspace(c))
		c = gc();
 
	if (c == EOF)
	{
		ungetc(c, stdin);
		return 1;
	}
 
	ungetc(c, stdin);
	return 0;
}
 
inline void pre()
{
	int i;
 
	fact[0] = 1;
 
	for (i = 1; i <= MAXN; i++)
	{
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
}
 
inline long long rev(long long num)
{
	return modpow(num, MOD - 2, MOD);
}
 
inline long long ncr(long long n, long long k)
{
	long long res = fact[n];
 
	res *= rev(fact[k]);
	res %= MOD;
 
	res *= rev(fact[n - k]);
	res %= MOD;
 
	return res;
}
 
inline void init()
{
	scanf("%lld %lld %lld %lld", &N, &A, &B, &D);
}
 
inline long long solve()
{
	long long res = ncr(N, A);
 
	res *= modpow(ncr(B, D), A, MOD);
	res %= MOD;
 
	return res;
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
 
	pre();
 
	while (!finish())
	{
		init();
		printf("%lld\n", solve());
	}
 
	return 0;
} 
