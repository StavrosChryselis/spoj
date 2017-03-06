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
 
using namespace std;
 
unsigned int A[1000007];
int N;
 
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
 
inline void init()
{
	int i;
 
	N = FAST_IO();
 
//	scanf("%d", &N);
 
	for (i = 0; i < N; i++)
		//scanf("%d", &A[i]);
		A[i] = FAST_IO();
}
 
inline int solve()
{
	int i;
	int xxor = 0;
	int pos = 0, ans = 0;
 
	xxor = A[0];
 
	for (i = 1; i < N; i++)
		xxor ^= A[i];
 
	if (xxor == 0)
		return 0;
 
	for (; xxor; pos++)
		xxor >>= 1;
 
	pos--;
 
	for (i = 0; i < N; i++)
		if ((A[i] >> pos) % 2)
			ans++;
 
	return ans;
}
 
int main()
{
	int T;
 
//	freopen("input.txt", "r", stdin);
	
	//scanf("%d", &T);
	T = FAST_IO();
 
	while (T--)
	{
		init();
		printf("%d\n", solve());
	}
 
	return 0;
} 
