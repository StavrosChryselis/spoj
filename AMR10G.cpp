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
 
using namespace std;
 
int A[20007];
int N, K;
 
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
 
inline void init()
{
	int i;
 
	//scanf("%d %d", &N, &K);
	N = FAST_IO();
	K = FAST_IO();
	
	for(i=0; i<N; i++)
		//scanf("%d", &A[i]);
		A[i] = FAST_IO();
 
	sort(A, A+N);
}
 
inline int solve()
{
	int i;
	int diff;
 
	if(K == 1)
		return 0;
	
	diff = A[K-1] - A[0];
 
	for(i=K; i<N; i++)
		diff = min(diff, A[i] - A[i-K+1]);
 
	return diff;
}
 
int main()
{
	int T;
 
	//freopen("input.txt","r",stdin);
 
	T = FAST_IO();
	//scanf("%d", &T);
 
	while(T--)
	{
		init();
		printf("%d\n", solve());
	}
 
	return 0;
} 
