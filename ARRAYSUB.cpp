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
#define max(a,b) (a>b)?a:b
 
int tree[1000007*4];
int A[1000007];
int N, K;
 
void init()
{
	int i;
 
	scanf("%d", &N);
 
	for(i = 1; i<=N; i++)
		scanf("%d", &A[i]);
 
	scanf("%d", &K);
}
 
void init_tree(int index, int a, int b)
{
	if(a==b)
	{
		tree[index] = A[a];
		return;
	}
 
	init_tree(index*2, a, (a+b)/2);
	init_tree(index*2+1, (a+b)/2+1, b);
 
	tree[index] = max(tree[index*2], tree[index*2+1]);
}
 
int query(int index, int a, int b, int i, int j)
{
	int mid;
 
	if(a==i && b==j)
		return tree[index];
 
	mid = (a+b)/2;
 
	if(j <= mid)
		return query(index*2, a, mid, i, j);
	else if(i > mid)
		return query(index*2+1, mid+1, b, i, j);
	
	return max(query(index*2, a, mid, i, mid), query(index*2+1, mid + 1, b, mid + 1, j));
}
 
int main()
{
	int i;
 
	//freopen("input.txt","r",stdin);
 
	init();
	init_tree(1, 1, N);
	for(i=K; i<=N; i++)
		printf("%d ", query(1, 1, N, i - K + 1, i));
 
	return 0;
}
