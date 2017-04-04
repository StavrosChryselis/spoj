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
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
 
using namespace std;
 
string A, B;
int N, M;
 
inline void init()
{
	cin >> N >> M;
	cin >> A;
	cin >> B;
}
 
inline int solve()
{
	int memoA[26], memoB[26];
	int i, rval = INT_MAX;
 
	memset(memoA, 0, sizeof(memoA));
	memset(memoB, 0, sizeof(memoB));
 
 
	for (i = 0; i < N; i++)
		memoA[A[i] - 'a']++;
 
	for (i = 0; i < M; i++)
		memoB[B[i] - 'a']++;
 
	for (i = 0; i < 26; i++)
		if (memoB[i])
			rval = min(rval, memoA[i] / memoB[i]);
 
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
