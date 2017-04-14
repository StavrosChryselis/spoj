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
#define MAXN 100007
using namespace std;

const ll MOD = 10e9 + 7;

int N;
ll A[MAXN];
bool flag;

inline void init()
{
	int i, num;

	cin >> N;

	memset(A, 0, sizeof(A));
	flag = 0;

	for (i = 0; i < N; i++)
	{
		cin >> num;
		A[num]++;

		if (A[num] > 1)
			flag = 1;
	}
}

inline ll solve()
{
	int i;
	ll rval = 0;

	for (i = 1; i < MAXN; i++)
		if (A[i])
			rval += A[i] * (N - A[i]);

	rval /= 2;

	return rval + flag;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	int T;

	cin >> T;

	while (T--)
	{
		init();
		cout << solve() << "\n";
	}

	return 0;
}
