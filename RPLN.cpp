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
#include <algorithm>
 
using namespace std;
 
int A[100007];
int tree[100007*4];
int N, Q;
 
void build(int node, int a, int b)
{
	if(a==b)
	{
		tree[node]=A[a];
		return;
	}
 
	build(node*2, a, (a+b)/2);
	build(node*2+1, (a+b)/2+1, b);
	tree[node]=min(tree[node*2], tree[node*2+1]);
}
 
int query(int node, int a, int b, int i, int j)
{
	if(a==i && b==j)
		return tree[node];
 
	if(j<=(a+b)/2)
		return query(node*2, a, (a+b)/2, i, j);
	if(i>(a+b)/2)
		return query(node*2+1, (a+b)/2+1, b, i, j);
 
	return min(query(node*2, a, (a+b)/2, i, (a+b)/2), query(node*2+1, (a+b)/2+1, b, (a+b)/2+1, j));
}
 
inline void init()
{
	int i;
 
	scanf("%d %d", &N, &Q);
 
	for(i=1; i<=N; i++)
		scanf("%d", &A[i]);
 
	build(1, 1, N);
}
 
int main()
{
	int T, i, j, f, s;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	for(i=1; i<=T; i++)
	{
		init();
		printf("Scenario #%d:\n\n", i);
 
		for(j=0; j<Q; j++)
		{
			scanf("%d %d", &f, &s);
			printf("%d\n", query(1, 1, N, f, s));
		}
	}
 
	return 0;
} 
