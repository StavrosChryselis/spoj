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
#include <ctype.h>
#define gc() getchar_unlocked()
 
#define MAXN 100007
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
 
struct node
{
	int num;
	int sum;
	struct node *left;
	struct node *right;
 
	node(int n)
	{
		num = n;
		sum = 1;
		left = right = nullptr;
	}
};
 
int C;
int N, M;
struct node *root;
int MAXNUM;
 
void add(struct node **curr, int num)
{
	if (*curr == nullptr)
	{
		*curr = new struct node(num);
		C++;
		return;
	}
 
	if (num < (*curr)->num)
	{
		add(&(*curr)->left, num);
		(*curr)->sum++;
	}
 
	else if (num >(*curr)->num)
		add(&(*curr)->right, num);
 
	else
	{
		(*curr)->sum++;
		C++;
	}
}
 
int count(struct node *curr, int num)
{
	if (curr == nullptr)
		return 0;
 
	if (curr->num <= num)
		return curr->sum + count(curr->right, num);
 
	return count(curr->left, num);
}
 
inline void init()
{
	int num, i;
 
	N = FAST_IO();
	M = FAST_IO();
 
	num = FAST_IO();
	MAXNUM = num;
 
	root = new struct node(num);
 
	for (i = 1; i < N; i++)
	{
		num = FAST_IO();
		MAXNUM = max(MAXNUM, num);
		add(&root, num);
	}
	C = N;
}
 
inline void one(int num)
{
	int a = count(root, num);
	MAXNUM = max(MAXNUM, num + a);
	add(&root, num + a);
}
 
inline void two(int num)
{
	printf("%d\n", count(root, num));
}
 
inline void three(int num)
{
	if (num > C)
	{
		printf("invalid\n");
		return;
	}
 
	int lo, hi, mid, t;
 
	lo = 0;
	hi = MAXNUM;
	mid = (lo + hi) / 2;
 
	while (lo != hi - 1)
	{
		t = count(root, mid);
 
		if (t < num)
			lo = mid;
		else
			hi = mid;
 
		mid = (lo + hi) / 2;
	}
 
	printf("%d\n", hi);
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
 
	int t, x;
 
	init();
 
	while (M--)
	{
		t = FAST_IO();
		x = FAST_IO();
 
		switch (t)
		{
		case 1:
			one(x);
			break;
		case 2:
			two(x);
			break;
		case 3:
			three(x);
			break;
		}
	}
 
	return 0;
} 
