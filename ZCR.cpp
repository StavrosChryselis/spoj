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
#include <iomanip>
#include <cstring>
#include <algorithm>

#define MAXN 1024
using namespace std;

int N, K;
double A[MAXN];
double DP[MAXN][MAXN];

inline void init()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> A[i];
}

inline double solve()
{
	int i, j;

	memset(DP, 0, sizeof(DP));
	DP[0][0] = 1;

	for (i = 1; i <= N; i++)
		DP[0][i] = DP[0][i - 1] * (1 - A[i]);

	for (j = 1; j <= K; j++)
		for (i = 1; i <= N; i++)
			DP[j][i] = DP[j][i - 1] + DP[j - 1][i - 1] * A[i];

	return min(1.00, DP[K][N]);
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
		cout << setiosflags(ios::fixed) << setprecision(10) << solve() << "\n";
	}

	return 0;
}
