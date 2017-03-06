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
 
using namespace std;
 
const long long MOD = 1000000007;
long long N, M;
 
template <typename T>
T modpow(T base, T exp, T modulus) {
	base %= modulus;
	T result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}
 
inline void init()
{
	scanf("%lld %lld", &N, &M);
}
 
inline long long solve()
{
	long long f, s;
 
	f = modpow(M, N, MOD);
 
	if (N % 2)
		s = modpow(M, N / 2 + 1, MOD);
	else
		s = modpow(M, N / 2, MOD);
 
	f = f - s;
	if (f < 0)
		f += MOD;
 
	return f;
}
 
int main()
{
	int T, i;
 
	scanf("%d", &T);
 
	for (i = 1; i <= T; i++)
	{
		init();
		printf("Case %d: %lld\n", i, solve());
	}
 
	return 0;
} 
