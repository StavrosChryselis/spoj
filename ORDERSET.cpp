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
#include <unordered_map>
#include <ctype.h>
#define gc() getchar_unlocked()
 
using namespace std;
 
int N;
 
unordered_map<int, int> link, reverse_link;
int RAW_INPUT[200007];
char type[200007];
bool exist[200007];
int tree[200007];
 
inline int FAST_IO()
{
	char ch;
	int val = 0;
	bool neg = 0;
 
	ch = gc();
	while (isspace(ch) && ch != EOF)
		ch = gc();
	val = 0;
	if (ch == '-')
	{
		neg = 1;
		ch = gc();
	}
 
	while (isdigit(ch))
	{
		val = (val * 10) + (ch - '0');
		ch = gc();
	}
 
	if(neg)
		return -val;
 
	return val;
 
}
 
inline char FAST_CHAR()
{
	char ch;
 
	ch = gc();
 
	while (isspace(ch))
		ch = gc();
 
	return ch;
}
 
inline void point_update(int pos, int val)
{
	for( ; pos <= 200006; pos += pos & (-pos))
		tree[pos] += val;
}
 
inline void range_update(int i, int j, int val)
{
	point_update(i, val);
	point_update(j + 1, -val);
}
 
inline int query(int pos)
{
	int sum = 0;
 
	for( ; pos > 0; pos -= pos & (-pos))
		sum += tree[pos];
	return sum;
}
 
void init()
{
	int i, t=2;
	int temp[200007];
	//scanf("%d\n", &N);
	N = FAST_IO();
 
	for(i=0; i<N; i++)
	{
		//scanf("%c %d\n", &type[i], &RAW_INPUT[i]);
		type[i] = FAST_CHAR();
		RAW_INPUT[i] = FAST_IO();
		temp[i]=RAW_INPUT[i];
	}
 
	sort(temp, temp + N);
 
	link[temp[0]] = 1;
	reverse_link[1] = temp[0];
 
	for(i=1; i<N; i++)
		if(temp[i]!=temp[i-1])
		{
			link[temp[i]]=t++;
			reverse_link[t-1]=temp[i];
		}
 
}
 
int main()
{
	int i, down, up, ans;
	int size=0;
 
	//freopen("input.txt","r",stdin);
 
	init();
 
	for(i=0; i<N; i++)
		switch(type[i])
		{
			case 'I':
				if(!exist[link[RAW_INPUT[i]]])
				{
					exist[link[RAW_INPUT[i]]]=1;
					range_update(link[RAW_INPUT[i]]+1, 200006, 1);
					size++;
				}
				break;
 
			case 'D':
				if(exist[link[RAW_INPUT[i]]])
				{
					exist[link[RAW_INPUT[i]]]=0;
					range_update(link[RAW_INPUT[i]]+1, 200006, -1);
					size--;
				}
				break;
 
			case 'C':
				printf("%d\n", query(link[RAW_INPUT[i]]));
				break;
 
			case 'K':
				if(size < RAW_INPUT[i])
					printf("invalid\n");
				else
				{
					down = 1;
					up = 200006;
					while(down != up-1)
					{
						ans=query((down+up)/2);
						if(ans >= RAW_INPUT[i])
							up = (down+up)/2;
						else if(ans < RAW_INPUT[i])
							down = (down+up)/2;
					}
					printf("%d\n", reverse_link[down]);
				}
				break;
	}
	return 0;
} 
