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
#include <functional>
#include <vector>
 
#include <ctype.h>
#define gc() getchar_unlocked()
using namespace std;
 
int N;
pair<int, int> people[10007];
 
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
 
struct node
{
	int val;
	int lesser;
	struct node *left;
	struct node *right;
 
	node(int v)
	{
		val = v;
		lesser = 0;
		left = right = NULL;
	}
};
 
void insert(struct node **curr, int val, int lesser)
{
	if (*curr == NULL)
	{
		*curr = new struct node(val);
		return;
	}
 
	if (lesser <= (*curr)->lesser)
	{
		(*curr)->lesser++;
		insert(&((*curr)->left), val, lesser);
	}
 
	else
		insert(&((*curr)->right), val, lesser - 1 - (*curr)->lesser);
}
 
void print(struct node *curr)
{
	if (curr == NULL)
		return;
 
	print(curr->left);
	printf("%d ", curr->val);
	print(curr->right);
}
 
struct node *root;
 
inline void init()
{
	int i;
 
	//scanf("%d", &N);
	N = FAST_IO();
 
	for (i = 0; i < N; i++)
		//scanf("%d", &people[i].first);
		people[i].first = FAST_IO();
 
	for (i = 0; i < N; i++)
		//scanf("%d", &people[i].second);
		people[i].second = FAST_IO();
 
 
	sort(people, people + N, greater<pair<int, int> >());
 
	root = new struct node(people[0].first);
}
 
int main()
{
	int T, i;
 
	//freopen("input.txt", "r", stdin);
 
	//scanf("%d", &T);
	T = FAST_IO();
	while (T--)
	{
		init();
		for (i = 1; i < N; i++)
			insert(&root, people[i].first, people[i].second);
		print(root);
		putchar('\n');
	}
 
	return 0;
} 
