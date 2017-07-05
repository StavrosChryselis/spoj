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

#define MAXN 200007
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

int N;
int tree[MAXN];
int A[MAXN];

inline void update(int pos)
{
	for (; pos <= N; pos += pos & (-pos))
		tree[pos]++;
}

inline int query(int pos)
{
	int rval = 0;

	for (; pos > 0; pos -= pos & (-pos))
		rval += tree[pos];

	return rval;
}

inline void init()
{
	int i;

	cin >> N;

	memset(tree, 0, sizeof(tree));

	for (i = N; i >= 1; i--)
		cin >> A[i];
}

inline ll solve()
{
	ll rval = 1;
	ll fact = 1;
	int i;

	for (i = 1; i <= N; i++)
	{
		if (i != 1)
			fact *= (i - 1);

		fact %= MOD;
		rval += fact * query(A[i]);
		rval %= MOD;
		update(A[i] + 1);
	}

	return rval;
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
