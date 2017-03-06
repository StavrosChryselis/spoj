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
#include <string.h>
 
#define gc() getchar()
 
using namespace std;
 
int N;
 
inline bool get_bit()
{
	char c;
 
	c = gc();
	gc();
	gc();
	gc();
 
	if (c == 'l')
		return 1;
 
	return 0;
}
 
inline void solve()
{
	bool v = 0;
	bool b;
 
	scanf("%d\n", &N);
 
	while (N--)
	{
		b = get_bit();
		v ^= b;
	}
 
	if (v)
		printf("lxh\n");
	else
		printf("hhb\n");
}
 
int main()
{
	int T;
 
//	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
 
	while (T--)
	{
		solve();
	}
 
	return 0;
} 
