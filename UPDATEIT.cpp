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
 
int tree[10007];
int N, U, Q;
 
inline void point_update(int pos, int val)
{
	for( ; pos<=N; pos += pos&(-pos))
		tree[pos] += val;
}
 
inline void range_update(int i, int j, int val)
{
	point_update(i, val);
	point_update(j+1, -val);
}
 
inline int point_query(int pos)
{
	int sum = 0;
 
	for( ; pos > 0; pos -= pos&(-pos))
		sum += tree[pos];
 
	return sum;
}
 
int main()
{
	int i, T;
	int f, s, val;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while(T--)
	{
		memset(tree, 0, sizeof(tree));
 
		scanf("%d %d", &N, &U);
		N++;
 
		for(i=0; i<U; i++)
		{
			scanf("%d %d %d", &f, &s, &val);
			range_update(f+1, s+1, val);
		}
 
		scanf("%d", &Q);
 
		for(i=0; i<Q; i++)
		{
			scanf("%d", &f);
			printf("%d\n", point_query(f+1));
		}
	}
 
	return 0;
} 
