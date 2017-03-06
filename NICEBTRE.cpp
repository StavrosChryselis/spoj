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
 
using namespace std;
 
struct node
{
	char info;
	struct node *left;
	struct node *right;
};
 
void construct(struct node **cur)
{
	char c;
 
	scanf("%c", &c);
 
	*cur=(struct node*)malloc(sizeof(struct node));
	(*cur)->info=c;
	(*cur)->left=NULL;
	(*cur)->right=NULL;
 
	if(c=='n')
	{
		construct(&(*cur)->left);
		construct(&(*cur)->right);
	}
}
 
int count(struct node *cur)
{
	if(cur->info=='l')
		return 0;
 
	return 1+max(count(cur->left), count(cur->right));
}
 
void free_node(struct node **cur)
{
	if((*cur)->info=='l')
	{
		free(*cur);
		return;
	}
 
	free_node(&(*cur)->left);
	free_node(&(*cur)->right);
	free(*cur);
}
 
int main()
{
	int T, i;
	struct node *root;
	scanf("%d\n", &T);
	char c;
 
	for(i=0; i<T; i++)
	{
		construct(&root);
		printf("%d\n", count(root));
		free_node(&root);
		scanf("%c", &c);
	}
 
	return 0;
} 
