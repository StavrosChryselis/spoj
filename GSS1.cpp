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
#include <stdlib.h>
#include <algorithm>
#define MAX 50007
using namespace std;
 
struct n
{
	long long left;
	long long right;
	long long all;
	long long best;
};
 
typedef struct n node;
 
node tree[MAX*4];
int arr[MAX+1];
int N, E;
 
void init(int index, int a, int b)
{	
	if(a==b)
	{
		tree[index].all=tree[index].best=tree[index].left=tree[index].right=arr[a];
		return;
	}
 
	init(index*2, a, (a+b)/2);
	init(index*2+1, (a+b)/2+1, b);
 
	tree[index].left=max(tree[index*2].left, tree[index*2].all+tree[index*2+1].left);
	tree[index].right=max(tree[index*2+1].right, tree[index*2+1].all + tree[index*2].right);
	tree[index].all=tree[index*2].all+tree[index*2+1].all;
	tree[index].best=max(tree[index*2].right+tree[index*2+1].left, max(tree[index*2].best, tree[index*2+1].best));
}
 
node query(int index, int a, int b, int i, int j)
{
	node temp;
	node *left, *right;
	
	if(a==i && b==j)
	{
		temp.all=tree[index].all;
		temp.best=tree[index].best;
		temp.left=tree[index].left;
		temp.right=tree[index].right;
 
		return temp;
	}
 
	if(j<=(a+b)/2)
		return query(index*2, a, (a+b)/2, i, j);
 
	else if(i>=(a+b)/2+1)
		return query(index*2+1, (a+b)/2+1, b, i, j);
 
	else
	{
		left=&query(index*2, a, (a+b)/2, i, (a+b)/2);
		right=&query(index*2+1, (a+b)/2+1, b, (a+b)/2+1, j);
 
		temp.all=left->all+right->all;
		temp.left=max(left->left, left->all + right->left);
		temp.right=max(right->right, right->all + left->right);
		temp.best=max(left->right+right->left, max(left->best, right->best));
 
		return temp;
	}
}
 
int main()
{
 
	int i;
	int f, s;
	node *temp;
 
	scanf("%d", &N);
 
	for(i=1; i<=N; i++)
		scanf("%d", &arr[i]);
 
	init(1, 1, N);
 
	scanf("%d", &E);
 
	for(i=0; i<E; i++)
	{
		scanf("%d %d", &f, &s);
		temp=&query(1, 1, N, f, s);
		printf("%lld\n", max(max(temp->best, temp->all), max(temp->left, temp->right)));
	}
 
	return 0;
} 
