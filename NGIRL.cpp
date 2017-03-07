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
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define SQ 100007
using namespace std;

const ll MAXN = 10e10;

vector< pair<ll, int> > prime_squares;
bool is_prime[SQ];
ll N, K;
int c;

inline void sieve()
{
	int i, j;
	
	c = 2;

	memset(is_prime, 1, sizeof(is_prime));

	prime_squares.push_back(make_pair(4, 1));

	for (i = 3; i < SQ; i += 2)
		if (is_prime[i])
		{
			prime_squares.push_back(make_pair((ll)i * (ll)i, c++));
			for (j = i + i; j < SQ; j += i)
				is_prime[j] = 0;
		}
}

inline void init()
{
	cin >> N >> K;
}

inline void solve()
{
	ll a1, a2;

	if (N < 1)
		cout << "0 0\n";

	K = min(K, N);

	a1 = prev(upper_bound(prime_squares.begin(), prime_squares.end(), make_pair(N, SQ)))->second;
	a2 = upper_bound(prime_squares.begin(), prime_squares.end(), make_pair(K, SQ))->second;

	cout << a1 << " " << a1 - a2 + 1 << "\n";

}
int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	sieve();
	
	int T;

	cin >> T;

	while (T--)
	{
		init();
		solve();
	}

	return 0;
}
