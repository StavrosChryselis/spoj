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
#include <vector>
#include <algorithm>
#include <ctype.h>
 
#define gc() getchar_unlocked();
 
using namespace std;
 
pair<int, int> MINMAX[4*200007];
int N, M;
int B[200007];
 
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
 
void init(int index, int a, int b)
{
	if(a == b)
	{
		MINMAX[index].first = MINMAX[index].second = a;
		return;
	}
 
	init(index*2, a, (a+b)/2);
	init(index*2+1, (a+b)/2+1, b);
 
	MINMAX[index].first = min(MINMAX[index*2].first, MINMAX[index*2+1].first);
	MINMAX[index].second = max(MINMAX[index*2].second, MINMAX[index*2+1].second);
}
 
void update(int index, int a, int b, int pos, int val)
{
	if(a == b && a == pos)
	{
		MINMAX[index].first = MINMAX[index].second = val;
		return;
	}
 
	if(pos <= (a+b)/2)
		update(index*2, a, (a+b)/2, pos, val);
	else
		update(index*2+1, (a+b)/2+1, b, pos, val);
 
	MINMAX[index].first = min(MINMAX[index*2].first, MINMAX[index*2+1].first);
	MINMAX[index].second = max(MINMAX[index*2].second, MINMAX[index*2+1].second);
}
 
pair<int, int> query(int index, int a, int b, int i, int j)
{
	if(a == i && b == j)
		return MINMAX[index];
 
	if(j <= (a+b)/2)
		return query(index*2, a, (a+b)/2, i, j);
	else if(i > (a+b)/2)
		return query(index*2+1, (a+b)/2+1, b, i, j);
	else
	{
		pair<int, int> left, right;
		left = query(index*2, a, (a+b)/2, i, (a+b)/2);
		right = query(index*2+1, (a+b)/2+1, b, (a+b)/2+1, j);
 
		return make_pair(min(left.first, right.first), max(left.second, right.second));
	}
}
 
int main()
{
	int i, f, s, t, j;
	pair<int, int> temp;
 
	//freopen("input.txt","r",stdin);
	N = FAST_IO();
	M = FAST_IO();
 
	//scanf("%d %d", &N, &M);
 
	for(i=1; i<=N; i++)		//B THESI A NANOI
		B[i] = i;
	init(1, 1, N);
 
	for(i=0; i<M; i++)
	{
		f = FAST_IO();
		s = FAST_IO();
		t = FAST_IO();
		//scanf("%d %d %d", &f, &s, &t);
 
		if(f == 1)
		{	
			update(1, 1, N, B[s], t);
			update(1, 1, N, B[t], s);
			swap(B[s], B[t]);
 
		}
 
		else
		{
			temp = query(1, 1, N, s, t);
	
			if(temp.second - temp.first == t - s)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
 
	return 0;
}  
