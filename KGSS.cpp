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
#include <ctype.h>
#define max(a,b) (a>b?a:b)
#define gc() getchar_unlocked()
 
int tree_max[100007*4];
int tree_best[100007*4];
int A[100007];
int N;
 
typedef struct 
{
	int best;
	int max;
}node;
 
inline int FAST_IO()
{
    char ch;
    int val=0;
    ch=gc();
    while(isspace(ch) && ch!=EOF)
            ch=gc();
    val=0;
    while(isdigit(ch))
    {
        val=(val*10)+(ch-'0');
        ch=gc();
    }
    return val;
}
 
inline char FAST_CHAR()
{
	char ch;
 
	ch=gc();
 
	while(isspace(ch))
		ch=gc();
 
	return ch;
}
 
void init_tree(int index, int a, int b)
{
	if(a == b)
	{
		tree_max[index] = tree_best[index] = A[a];
		return;
	}
 
	init_tree(index*2, a, (a+b)/2);
	init_tree(index*2+1, (a+b)/2+1, b);
 
	tree_max[index] = max(tree_max[index*2], tree_max[index*2+1]);
	tree_best[index] = max(tree_max[index*2] + tree_max[index*2+1], max(tree_best[index*2], tree_best[index*2+1]));
}
 
void update(int index, int a, int b, int pos, int val)
{
	if(a == b && a == pos)
	{
		tree_max[index] = tree_best[index] = val;
		return;
	}
 
	if(pos <= (a+b)/2)
		update(index*2, a, (a+b)/2, pos, val);
	else
		update(index*2+1, (a+b)/2+1, b, pos, val);
 
	tree_max[index] = max(tree_max[index*2], tree_max[index*2+1]);
	tree_best[index] = max(tree_max[index*2] + tree_max[index*2+1], max(tree_best[index*2], tree_best[index*2+1]));
}
 
node query(int index, int a, int b, int i, int j)
{
	node left, right, curr;
 
	if(a == i && b == j)
	{
		curr.best=tree_best[index];
		curr.max=tree_max[index];
		return curr;
	}
 
	if(j <= (a+b)/2)
		return query(index*2, a, (a+b)/2, i, j);
	else if(i > (a+b)/2)
		return query(index*2+1, (a+b)/2+1, b, i, j);
	
	left = query(index*2, a, (a+b)/2, i, (a+b)/2);
	right = query(index*2+1, (a+b)/2+1, b, (a+b)/2+1, j);
 
	curr.max = max(left.max, right.max);
	curr.best = max(left.max + right.max, max(left.best, right.best));
 
	return curr;
}
 
 
int main()
{
	int M, i;
	int f, s;
	char type;
 
	//freopen("input.txt","r",stdin);
 
	N=FAST_IO();
 
	for(i=1; i<=N; i++)
		A[i]=FAST_IO();
 
	init_tree(1, 1, N);
 
	M=FAST_IO();
	for(i=0; i<M; i++)
	{
 
		type=FAST_CHAR();
		f=FAST_IO();
		s=FAST_IO();
 
		if(type == 'U')
			update(1, 1, N, f, s);
		else
			printf("%d\n", query(1, 1, N, f, s).best);
	}
 
 
	return 0;
} 
