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
 
using namespace std;
 
int tree[100007*4];
bool lazy[100007*4];
int N, E;
 
void update(int node, int a, int b, int i, int j)
{
	if(lazy[node])
	{
		tree[node]=b-a+1-tree[node];
		if(a!=b)
		{
			lazy[node*2]=!lazy[node*2];
			lazy[node*2+1]=!lazy[node*2+1];
		}
		lazy[node]=0;
	}
 
 
	if(a==i && b==j)
	{
		tree[node]=b-a+1-tree[node];
		if(a!=b)
		{
			lazy[node*2]=!lazy[node*2];
			lazy[node*2+1]=!lazy[node*2+1];
		}
		return;
	}
 
	if(j<=(a+b)/2)
		update(2*node, a, (a+b)/2, i, j);
 
	else if(i>=(a+b)/2+1)
		update(2*node+1, (a+b)/2+1, b, i, j);
 
	else
	{
		update(2*node, a, (a+b)/2, i, (a+b)/2);
		update(2*node+1, (a+b)/2+1, b, (a+b)/2+1, j);
	}
 
	tree[node]=0;
	int mid = (a+b)/2;
 
	if(lazy[node*2])
		tree[node]+=mid-a+1-tree[node*2];
	else
		tree[node]+=tree[node*2];
	
	if(lazy[node*2+1])
		tree[node]+=b-(mid+1)+1-tree[node*2+1];
	else
		tree[node]+=tree[node*2+1];
	return;
}
 
int query(int node, int a, int b, int i, int j)
{
	if(lazy[node])
	{
		tree[node]=b-a+1-tree[node];
		if(a!=b)
		{
			lazy[node*2]=!lazy[node*2];
			lazy[node*2+1]=!lazy[node*2+1];
		}
		lazy[node]=0;
	}
 
 
	if(a==i && b==j)
		return tree[node];
 
	if(j<=(a+b)/2)
		return query(node*2, a, (a+b)/2, i, j);
	if(i>=(a+b)/2+1)
		return query(node*2+1, (a+b)/2+1, b, i, j);
 
	return query(2*node, a, (a+b)/2, i, (a+b)/2) + query(2*node+1, (a+b)/2+1, b, (a+b)/2+1, j);
}
 
 
 
 
		
int main()
{
	int i, f, s, type;
	scanf("%d %d", &N, &E);
 
	for(i=0; i<E; i++)
	{
		scanf("%d %d %d", &type, &f, &s);
 
		if(type==0)
			update(1, 1, N, f, s);
		else
			printf("%d\n", query(1, 1, N, f, s));
	}
 
	return 0;
} 
