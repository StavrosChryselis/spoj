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
#include <string.h>
 
using namespace std;
 
typedef struct
{
	int max_occ_num;
	int max_occ;
	int max_num;
	int max_num_occ;
	int min_num;
	int min_num_occ;
}node;
 
node tree[100007*4];
int A[100007];
int N, Q;
 
void inittree(int index, int a, int b)
{
	if(a==b)
	{
		tree[index].max_occ_num=A[a];
		tree[index].max_occ=1;
		tree[index].max_num=A[a];
		tree[index].max_num_occ=1;
		tree[index].min_num=A[a];
		tree[index].min_num_occ=1;
		
		return;
	}
 
	inittree(index*2, a, (a+b)/2);
	inittree(index*2+1, (a+b)/2+1, b);
 
	tree[index].max_occ_num=0;
	tree[index].max_occ=0;
	tree[index].max_num=0;
	tree[index].max_num_occ=0;
	tree[index].min_num=0;
	tree[index].min_num_occ=0;
 
	tree[index].min_num = tree[index*2].min_num;
	tree[index].min_num_occ = tree[index*2].min_num_occ;
	if(tree[index].min_num == tree[index*2+1].min_num)
		tree[index].min_num_occ+=tree[index*2+1].min_num_occ;
 
	tree[index].max_num = tree[index*2+1].max_num;
	tree[index].max_num_occ = tree[index*2+1].max_num_occ;
	if(tree[index].max_num == tree[index*2].max_num)
		tree[index].max_num_occ+=tree[index*2].max_num_occ;
 
	if(tree[index*2].max_num == tree[index*2+1].min_num)
	{
		tree[index].max_occ_num = tree[index*2].max_num;
		tree[index].max_occ = tree[index*2].max_num_occ + tree[index*2+1].min_num_occ;
	}
	
	if(tree[index].max_occ < tree[index*2].max_occ)
	{
		tree[index].max_occ = tree[index*2].max_occ;
		tree[index].max_occ_num = tree[index*2].max_occ_num;
	}
 
	if(tree[index].max_occ < tree[index*2+1].max_occ)
	{
		tree[index].max_occ = tree[index*2+1].max_occ;
		tree[index].max_occ_num = tree[index*2+1].max_occ_num;
	}
}
 
node query(int index, int a, int b, int i, int j)
{
	node left, right, treeindex;
 
	if(a==i && b==j)
		return tree[index];
 
	if(j<=(a+b)/2)
		return query(index*2, a, (a+b)/2, i, j);
	if(i>(a+b)/2)
		return query(index*2+1, (a+b)/2+1, b, i, j);
 
	left=query(index*2, a, (a+b)/2, i, (a+b)/2);
	right=query(index*2+1, (a+b)/2+1, b, (a+b)/2+1, j);
 
	treeindex.max_occ_num=0;
	treeindex.max_occ=0;
	treeindex.max_num=0;
	treeindex.max_num_occ=0;
	treeindex.min_num=0;
	treeindex.min_num_occ=0;
 
	treeindex.min_num = left.min_num;
	treeindex.min_num_occ = left.min_num_occ;
	if(treeindex.min_num == right.min_num)
		treeindex.min_num_occ+=right.min_num_occ;
 
	treeindex.max_num = right.max_num;
	treeindex.max_num_occ = right.max_num_occ;
	if(treeindex.max_num == left.max_num)
		treeindex.max_num_occ+=left.max_num_occ;
 
	if(left.max_num == right.min_num)
	{
		treeindex.max_occ_num = left.max_num;
		treeindex.max_occ = left.max_num_occ + right.min_num_occ;
	}
	
	if(treeindex.max_occ < left.max_occ)
	{
		treeindex.max_occ = left.max_occ;
		treeindex.max_occ_num = left.max_occ_num;
	}
 
	if(treeindex.max_occ < right.max_occ)
	{
		treeindex.max_occ = right.max_occ;
		treeindex.max_occ_num = right.max_occ_num;
	}
 
	return treeindex;
}
 
bool init()
{
	int i;
 
	scanf("%d", &N);
 
	if(N==0)
		return 0;
 
	scanf("%d", &Q);
	
	for(i=1; i<=N; i++)
		scanf("%d", &A[i]);
 
	inittree(1, 1, N);
 
	return 1;
}
 
 
int main()
{
	int i;
	int s, f;
 
	//freopen("input.txt","r",stdin);
 
	while(init())
		for(i=0; i<Q; i++)
		{
			scanf("%d %d", &s, &f);
			printf("%d\n", query(1, 1, N, s, f).max_occ);
		}
	return 0;
} 
