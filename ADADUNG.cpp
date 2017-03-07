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
#include <cstring>

#define ll long long
#define MAXN 10000007
using namespace std;

const ll MOD = 1000000007;
ll memo[MAXN];

ll derangement(ll num)
{
	if (num <= 1)
		return 0;

	if (num == 2)
		return 1LL;

	if (memo[num])
		return memo[num];

	ll temp = derangement(num - 1) + derangement(num - 2);

	temp %= MOD;

	memo[num] = (num - 1) * temp;
	memo[num] %= MOD;

	return memo[num];
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	int T, N;

	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << derangement(N) << "\n";
	}

	return 0;
}
