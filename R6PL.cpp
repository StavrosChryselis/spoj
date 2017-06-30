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
#include <cstring>

#define MAXN 207
#define MAXV 257
using namespace std;

bool DP[MAXN][MAXN * MAXV];
int N;

inline void init()
{
	cin >> N;
	memset(DP, 0, sizeof(DP));
	DP[0][0] = 1;
}

inline int solve()
{
	int i, j, x, y;

	for (i = 0; i < N; i++)
	{
		cin >> x >> y;
		int diff = max(x, y) - min(x, y);

		for (j = 0; j < MAXN * MAXV; j++)
			if (DP[i][j])
			{
				DP[i + 1][j + diff] = 1;
				if (j - diff >= 0)
					DP[i + 1][j - diff] = 1;
				else
					DP[i + 1][diff - j] = 1;
			}
	}

	for (i = 0; i < MAXN * MAXV; i++)
		if (DP[N][i])
			return i;

	return -1;
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
