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
#include <ctype.h>
#define gc() getchar_unlocked()
 
int N;
long long tree1[100007];
long long tree2[100007];
 
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
 
inline void point_update_1(int pos, long long val)
{
	for( ; pos <= N; pos += pos & (-pos))
		tree1[pos] += val;
}
 
inline void point_update_2(int pos, long long val)
{
	for( ; pos <= N; pos += pos & (-pos))
		tree2[pos] += val;
}
 
inline void range_update(int i, int j, long long val)
{
	point_update_1(i, val);
	point_update_1(j + 1, -val);
 
	point_update_2(i, val * (i-1));
	point_update_2(j + 1, - val * j);
}
 
inline long long point_query_1(int pos)
{
	long long sum = 0;
 
	for(; pos > 0; pos -= pos & (-pos))
		sum += tree1[pos];
	
	return sum;
}
 
inline long long point_query_2(int pos)
{
	long long sum = 0;
 
	for(; pos > 0; pos -= pos & (-pos))
		sum += tree2[pos];
	
	return sum;
}
 
inline long long start_query(int pos)
{
	return point_query_1(pos) * pos - point_query_2(pos);
}
 
inline long long range_query(int i, int j)
{
	return start_query(j) - start_query(i-1);
}
 
int main()
{
	int T, Q;
	int type, f, s, val;
 
//	freopen("input.txt","r",stdin);
 
	T=FAST_IO();
 
	while(T--)
	{
		memset(tree1, 0, sizeof(tree1));
		memset(tree2, 0, sizeof(tree2));
 
		N=FAST_IO();
		Q=FAST_IO();
 
		while(Q--)
		{
			type=FAST_IO();
			f=FAST_IO();
			s=FAST_IO();
 
			if(type==0)
			{
				val=FAST_IO();
				range_update(f, s, val);
			}
 
			else
				printf("%lld\n", range_query(f, s));
		}
	}
 
	return 0;
} 
