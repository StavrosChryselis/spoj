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

#include <string.h>
#include <stdio.h>
#include <ctype.h>
 
#define gc() getchar_unlocked()
 
using namespace std;
 
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
 
class BITPQ
{
private:
	int tree[50007];
	int N;
 
public:
	BITPQ(int n = 50007)
	{
		N = n;
		memset(tree, 0, sizeof(tree));
	}
 
	inline void reset(int n = 50007)
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
 
int A[50007];
BITPQ tree;
int N;
 
inline void init()
{
	int i;
 
	N = FAST_IO();
	tree.reset();
 
	for (i = 1; i <= N; i++)
	{
		A[i] = FAST_IO();
		tree.point_update(A[i], 1);
	}
}
 
inline long long solve()
{
	long long ans = 0;
	int i;
 
	for (i = 1; i <= N; i++)
		ans += tree.point_query(A[i]);
 
	return ans;
}
 
int main()
{
	int T;
 
	//freopen("input.txt", "r", stdin);
 
	T = FAST_IO();
 
	while (T--)
	{
		init();
		printf("%lld\n", solve());
	}
 
	return 0;
} 
