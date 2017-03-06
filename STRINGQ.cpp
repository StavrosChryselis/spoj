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
#include <string>
#include <ctype.h>
 
#define gc() getchar()
#define MOD 106109099
 
using namespace std;
 
typedef struct
{
	int count[26];
	int sum;
	bool lazy;
	int marked;
 
	inline void reset()
	{
		memset(count, 0, sizeof(count));
		sum = 0;
		marked = 0;
		lazy = 0;
	}
 
	inline void mark(int val)
	{
		marked = val;
		lazy = 1;
	}
 
	inline void update()
	{
		int temp = marked;
		int s = sum;
 
		reset();
 
		count[temp] = s;
		sum = s;
	}
 
}node;
 
node tree[4 * 50007];
long long fact[50007];
long long inverse[50007];
string S;
int N, M;
 
int mul_inv(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
 
	if (b == 1) 
		return 1;
 
	while (a > 1) 
	{
		q = a / b;
 
		t = b;
		b = a % b;
		a = t;
 
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}
 
	if (x1 < 0) 
		x1 += b0;
 
	return x1;
}
 
inline void preinit()
{
	int i;
 
	fact[0] = 1;
 
	for (i = 1; i <= 50000; i++)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
		inverse[i] = mul_inv(fact[i], MOD);
	}
}
 
inline void getstring(string &A)
{
	char c;
 
	A.clear();
 
	c = gc();
 
	while (isspace(c))
		c = gc();
 
	while (!isspace(c) && c != EOF)
	{
		A.push_back(c);
		c = gc();
	}
}
 
inline bool check(node &curr, bool is_odd)
{
	int i;
 
	if (!is_odd)
	{
		for (i = 0; i < 26; i++)
			if (curr.count[i] % 2)
				return 0;
	}
 
	else
	{
		int c = 0;
 
		for (i = 0; i < 26; i++)
			if (curr.count[i] % 2)
			{
				if (c)
					return 0;
				c = 1;
			}
	}
 
	return 1;
}
 
inline long long get_palindromes(node &a)
{
	int i;
	long long ans = fact[a.sum / 2];
 
	for (i = 0; i < 26; i++)
		if (a.count[i] / 2 > 1)
			ans = (ans * inverse[a.count[i] / 2]) % MOD;
 
	return ans;
}
 
//SEGMENT TREE FUNCTIONS
 
inline void merge(node &parent, node &left, node &right)
{
	int i;
 
	for (i = 0; i < 26; i++)
		parent.count[i] = left.count[i] + right.count[i];
 
	parent.sum = left.sum + right.sum;
}
 
inline void merge2(node &parent, node &child)
{
	int i;
 
	for (i = 0; i < 26; i++)
		parent.count[i] += child.count[i];
}
 
void init_tree(int index, int a, int b)
{
	if (a == b)
	{
		tree[index].reset();
		tree[index].count[S[a - 1] - 'a'] = 1;
		tree[index].sum = 1;
		return;
	}
 
	int mid = (a + b) / 2;
 
	init_tree(index * 2, a, mid);
	init_tree(index * 2 + 1, mid + 1, b);
 
	merge(tree[index], tree[index * 2], tree[index * 2 + 1]);
}
 
node *query(int index, int a, int b, int i, int j)
{
	if (tree[index].lazy)
	{
		if (a != b)
		{
			tree[index * 2].lazy = 1;
			tree[index * 2].mark(tree[index].marked);
 
			tree[index * 2 + 1].lazy = 1;
			tree[index * 2 + 1].mark(tree[index].marked);
		}
 
		tree[index].update();
	}
 
	if (i == a && j == b)
	{
		node *q = new node;
		*q = tree[index];
		return q;
	}
 
	int mid = (a + b) / 2;
 
	if (j <= mid)
		return query(index * 2, a, mid, i, j);
 
	if (i > mid)
		return query(index * 2 + 1, mid + 1, b, i, j);
 
	node *q = new node;
	node *l, *r;
 
	l = query(index * 2, a, mid, i, mid);
	r = query(index * 2 + 1, mid + 1, b, mid + 1, j);
 
	merge(*q, *l, *r);
	delete l;
	delete r;
 
	return q;
}
 
void replace(int index, int a, int b, int i, int j, int val)
{
	if (tree[index].lazy)
	{
		if (a != b)
		{
			tree[index * 2].lazy = 1;
			tree[index * 2].mark(tree[index].marked);
 
			tree[index * 2 + 1].lazy = 1;
			tree[index * 2 + 1].mark(tree[index].marked);
		}
 
		tree[index].update();
	}
 
	if (a == i && b == j)
	{
		tree[index].mark(val);
		tree[index].update();
 
		if (a != b)
		{
			tree[index * 2].lazy = 1;
			tree[index * 2].mark(val);
 
			tree[index * 2 + 1].lazy = 1;
			tree[index * 2 + 1].mark(val);
		}
 
		return;
	}
 
	int mid = (a + b) / 2;
 
	if (j <= mid)
		replace(index * 2, a, mid, i, j, val);
 
	else if (i > mid)
		replace(index * 2 + 1, mid + 1, b, i, j, val);
 
	else
	{
		replace(index * 2, a, mid, i, mid, val);
		replace(index * 2 + 1, mid + 1, b, mid + 1, j, val);
	}
 
	tree[index].reset();
 
	if (tree[index * 2].lazy)
		tree[index].count[tree[index * 2].marked] += tree[index * 2].sum;
	else
		merge2(tree[index], tree[index * 2]);
 
	if (tree[index * 2 + 1].lazy)
		tree[index].count[tree[index * 2 + 1].marked] += tree[index * 2 + 1].sum;
	else
		merge2(tree[index], tree[index * 2 + 1]);
	
	tree[index].sum = tree[index * 2].sum + tree[index * 2 + 1].sum;
}
 
inline void update(int i, int j)
{
	node *t = query(1, 1, N, i, j);
 
	int ii, temp = i;
 
	for (ii = 0; ii < 26; ii++)
		if (t->count[ii])
		{
			replace(1, 1, N, temp, temp + t->count[ii] - 1, ii);
			temp = temp + t->count[ii];
		}
 
	delete t;
}
 
inline char get_alpha(node &t)
{
	int i;
 
	for (i = 0; i < 26; i++)
		if (t.count[i])
			return i + 'a';
 
	return 0;
}
 
inline void print_final()
{
	node *t;
	int i;
 
	for (i = 0; i < S.length(); i++)
	{
		t = query(1, 1, N, i + 1, i + 1);
		putchar(get_alpha(*t));
 
		delete t;
	}
 
	putchar('\n');
}
 
inline void init()
{
	getstring(S);
	N = S.length();
 
	scanf("%d\n", &M);
	init_tree(1, 1, N);
}
 
int main()
{
	int T, i, f, s;
	char c;
	node *t;
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
 
	scanf("%d", &T);
	
	preinit();
 
	while (T--)
	{
		init();
 
		for (i = 0; i < M; i++)
		{
			scanf("%c %d %d\n", &c, &f, &s);
 
			switch (c)
			{
			case 'Q':
				t = query(1, 1, N, f, s);
				if (!check(*t, t->sum % 2))
					printf("0\n");
				else
					printf("%lld\n", get_palindromes(*t));
 
				delete t;
				break;
 
			case 'U':
				update(f, s);
				break;
			}
		}
 
		print_final();
	}
 
	return 0;
} 
