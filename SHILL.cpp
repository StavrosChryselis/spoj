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
#include <vector>
#include <ctype.h>
 
using namespace std;
 
#define INF 1000000007
#define gc() getchar_unlocked()
 
vector< vector< pair<int, int> > > G;
bool marked[100007];
 
int N;
 
inline int FAST_IO()
{
	char ch;
	int val = 0;
	ch = gc();
	while (isspace(ch) && ch != EOF)
		ch = gc();
	val = 0;
	while (isdigit(ch))
	{
		val = (val * 10) + (ch - '0');
		ch = gc();
	}
	return val;
}
 
inline void init()
{
	int i, j;
	int num, M;
 
	//scanf("%d", &N);
	N = FAST_IO();
 
	G.resize(N + 1);
 
	for (i = 1; i <= N; i++)
	{
		//scanf("%d", &M);
		M = FAST_IO();
 
		for (j = 0; j < M; j++)
		{
			//scanf("%d", &num);
			num = FAST_IO();
			G[i].push_back(make_pair(num, 0));
		}
 
		for (j = 0; j < M; j++)
		{
			//scanf("%d", &num);
			num = FAST_IO();
			G[i][j].second = num;
		}
	}
}
 
long long dfs(int curr)
{
	if (G[curr].size() == 0)
		return INF;
 
	int i;
	long long sum = 0, val;
 
	for (i = 0; i < G[curr].size(); i++)
	{
		val = dfs(G[curr][i].first);
 
		if (val <= G[curr][i].second)
			sum += val;
		else
		{
			marked[G[curr][i].first] = 1;
			sum += G[curr][i].second;
		}
	}
 
	return sum;
}
 
inline void print(int curr)
{
	int i;
 
	for (i = 0; i < G[curr].size(); i++)
	{
		if (!marked[G[curr][i].first])
			print(G[curr][i].first);
		else
			printf("%d ", G[curr][i].second);
	}
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
 
	init();
 
	if (N == 1)
		printf("0\n");
	else
		printf("%lld\n", dfs(1));
 
	print(1);
 
	return 0;
} 
