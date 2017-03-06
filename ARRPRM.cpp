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

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
 
#define MAXN 2007
using namespace std;
 
vector<int> primes;
bool is_prime[MAXN];
int memo[MAXN];
int A[MAXN];
int SUM[MAXN];
int N;
 
inline void sieve()
{
	int i, j;
 
	primes.push_back(2);
 
	memset(is_prime, 1, sizeof(is_prime));
 
	for (i = 4; i < MAXN; i += 2)
		is_prime[i] = 0;
 
	for (i = 3; i < MAXN; i += 2)
		if (is_prime[i])
		{
			primes.push_back(i);
 
			for (j = i + i; j < MAXN; j += i)
				is_prime[j] = 0;
		}
}
 
inline void init()
{
	int i;
 
	cin >> N;
 
	for (i = 1; i <= N; i++)
	{
		cin >> A[i];
		SUM[i] = SUM[i - 1] + A[i];
	}
 
	memset(memo, -1, sizeof(memo));
}
 
inline int get_sum(int b, int e)
{
	return SUM[e] - SUM[b - 1];
}
 
int f(int left)
{
	int b, i, rval = 0;
 
	if (left <= 1)
		return 0;
 
	if (memo[left] != -1)
		return memo[left];
 
	b = N - left + 1;
 
	for (i = 0; primes[i] <= left && i < primes.size(); i++)
		rval = max(rval, get_sum(b, b + primes[i] - 1) + f(left - primes[i] - 1));
 
	rval = max(rval, f(left - 1));
 
	memo[left] = rval;
 
	return rval;
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
 
	int T;
 
	sieve();
 
	cin >> T;
 
	while (T--)
	{
		init();
		cout << f(N) << "\n";
	}
 
	return 0;
} 
