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
 
#define MOD 1000000007
using namespace std;
 
long long nCr[50][50];
long long A, B;
 
long long modular_pow(long long base, long long exponent, long long modulus)
{
	long long result = 1;
 
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}
 
inline void init()
{
	int i, j;
 
	for (i = 0; i < 50; i++)
		nCr[i][0] = nCr[i][i] = 1;
 
	for (i = 1; i < 50; i++)
		for (j = 1; j <= i / 2; j++)
		{
			nCr[i][j] = nCr[i][i - j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
			nCr[i][j] %= MOD;
			nCr[i][i - j] %= MOD;
			
		}
 
}
 
inline long long solve()
{
	long long mmax, mmin;
	long long result = 0, p;
 
	mmax = max(A, B);
	mmin = min(A, B);
 
	if (mmax < 25)
		return 0;
	
	if (mmax == 25 && mmax - mmin < 2)
		return 0;
 
	if (mmax == 25)
		return nCr[mmax + mmin - 1][mmin];
	
	if (mmax - mmin != 2)
		return 0;
 
	result = nCr[48][24];
	p = modular_pow(2, mmin - 24, MOD);
 
	result = (result * p) % MOD;
 
	return result;
}
 
int main()
{
	int T;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
	init();
 
	while (T--)
	{
		scanf("%lld %lld", &A, &B);
		printf("%lld\n", solve());
	}
 
	return 0;
} 
