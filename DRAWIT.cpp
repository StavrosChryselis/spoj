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
 
#define MAXN 128
using namespace std;
 
int deg[MAXN];
int N, E;
 
inline void init()
{
	int i, f, s, w;
 
	memset(deg, 0, sizeof(deg));
 
	cin >> N >> E;
 
	for (i = 0; i < E; i++)
	{
		cin >> f >> s >> w;
		deg[f] += w;
		deg[s] += w;
	}
}
 
inline int solve()	//0 if not, 1 if all even, 2 if 2 odds
{
	int i, c = 0;
 
	for (i = 1; i <= N; i++)
		if (deg[i] % 2)
			c++;
 
	if (!c)
		return 1;
	if (c == 2)
		return 2;
 
	return 0;
}
 
inline void print(int c)
{
	if (c == 1)
	{
		cout << "1\n";
		return;
	}
 
	int i;
 
	for (i = 1; i <= N; i++)
		if (deg[i] % 2)
		{
			cout << i << "\n";
			return;
		}
}
 
int main()
{
	ios::sync_with_stdio(0);
 
	int T, c;
 
//	freopen("input.txt", "r", stdin);
 
	cin >> T;
 
	while (T--)
	{
		init();
		c = solve();
 
		if (!c)
			cout << "NO\n";
		else
		{
			cout << "YES ";
			print(c);
		}
	}
 
	return 0;
} 
