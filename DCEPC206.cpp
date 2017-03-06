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
 
#define gc() getchar_unlocked()
 
long long tree[10][1000007];
 
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
 
inline void update(int i, int pos, int val)
{
	for( ; pos <= 1000006; pos += pos&(-pos))
		tree[i][pos] += val;
}
 
inline long long query(int i, int pos)
{
	long long sum = 0;
 
	for( ; pos>0; pos -= pos&(-pos))
		sum += tree[i][pos];
 
	return sum;
}
 
int main()
{
	int T, t, i, N, num;
	long long sum;
 
	//freopen("input.txt","r",stdin);
 
	T=FAST_IO();
 
	for(t=0; t<T; t++)
	{
		sum=0;
 
		N=FAST_IO();
 
		for(i=0; i<N; i++)
		{
			num=FAST_IO();
 
			if(num!=0)
				update(t, num+1, num);
			sum += query(t, num);
		}
 
		printf("%lld\n", sum);
	}
 
	return 0;
} 
