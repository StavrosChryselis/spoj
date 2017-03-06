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
#include <string.h>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#define gc() getchar_unlocked()
 
using namespace std;
 
int N, Q, MAX;
int A[100007], B[100007];
unordered_map<int, int> map;
vector< int > appear[100007];
int ans[100007];
typedef pair< pair<int, int>, pair<int, int> > query; //i, k, l, pos
vector<query> QUERIES;
 
inline int FAST_IO()
{
	char ch;
	int val = 0;
	bool neg = 0;
 
	ch = gc();
	while (isspace(ch) && ch != EOF)
		ch = gc();
	val = 0;
 
	if (ch == '-')
	{
		neg = 1;
		ch = gc();
	}
 
	while (isdigit(ch))
	{
		val = (val * 10) + (ch - '0');
		ch = gc();
	}
 
	if(neg)
		return -val;
 
	return val;
}
 
class BITPQ
{
	private:
		int tree[100007];
		int N;
 
	public:
		BITPQ(int n)
		{
			N = n;
			memset(tree, 0, sizeof(tree));
		}
 
		inline void point_update(int pos, int val)
		{
			for (; pos <= N; pos += pos&(-pos))
				tree[pos] += val;
		}
 
		inline void range_update(int i, int j, int val)
		{
			point_update(i, val);
			point_update(j + 1, -val);
		}
 
		inline int point_query(int pos)
		{
			int sum = 0;
 
			for (; pos > 0; pos -= pos&(-pos))
				sum += tree[pos];
 
			return sum;
		}
};
 
BITPQ *BIT;
inline void init()
{
	int i, c;
	query temp;
 
	N = FAST_IO();
	Q = FAST_IO();
	//scanf("%d %d", &N, &Q);
 
	BIT = new BITPQ(N);
 
	for (i = 0; i < N; i++)
	{
		A[i] = FAST_IO();
	//	scanf("%d", &A[i]);
		B[i] = A[i];
	}
 
	sort(B, B + N);
 
	map[B[0]] = 1;
 
	c = 2;
	for (i = 1; i < N; i++)
		if (B[i] != B[i - 1])
			map[B[i]] = c++;
 
	MAX = map[B[N - 1]];
 
	for (i = 0; i < N; i++)
		appear[map[A[i]]].push_back(i);
 
	for (i = 0; i < Q; i++)
	{
		temp.second.second = i;
 
		temp.first.second = FAST_IO();
		temp.first.first = FAST_IO();
		temp.second.first = FAST_IO();
		//scanf("%d %d %d", &temp.first.second, &temp.first.first, &temp.second.first);
		QUERIES.push_back(temp);
	}
 
	sort(QUERIES.begin(), QUERIES.end());
}
 
inline int solve_query(int k, int l)
{
	if (k == 0)
		return -1;
 
	int lo = 1, hi = MAX + 1, mid;
 
	while (lo + 1 != hi)
	{
		mid = (lo + hi) / 2;
		if (BIT->point_query(mid) <= k - 1)
			lo = mid;
		else
			hi = mid;
	}
 
	//if (BIT->point_query(lo) != k - 1)
	//	return -1;
 
	if (appear[lo].size() < l)
		return -1;
 
	return appear[lo][l - 1];
}
 
inline void solve()
{
	int i = 0, j;
 
	for (j = 0; j < QUERIES.size(); j++)
	{
		for (; i <= min(QUERIES[j].first.first, N - 1); i++)
			BIT->range_update(map[A[i]] + 1, MAX + 1, 1);
 
		ans[QUERIES[j].second.second] = solve_query(QUERIES[j].first.second, QUERIES[j].second.first);
	}
}
 
inline void print()
{
	int i;
 
	for (i = 0; i < Q; i++)
		printf("%d\n", ans[i]);
}
 
 
int main()
{
	//freopen("input.txt", "r", stdin);
 
	init();
	solve();
	print();
 
	delete BIT;
 
	return 0;
} 
