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
 
using namespace std;
 
class BITPQ
{
private:
	int tree[1000007];
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
 
BITPQ tree(1000006);
int N, M, L;
 
inline void init()
{
	scanf("%d %d %d", &N, &M, &L);
}
 
int main()
{
	int f, s;
 
//	freopen("input.txt", "r", stdin);
 
	init();
 
	while (N--)
	{
		scanf("%d %d", &f, &s);
		tree.range_update(f + 1, s + 1, 1);
	}
 
	while (M--)
	{
		scanf("%d", &f);
		printf("%d\n", tree.point_query(f + 1));
	}
 
	return 0;
} 
