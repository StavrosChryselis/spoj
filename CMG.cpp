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
 
#define gc() getchar_unlocked()
 
using namespace std;
 
int A[100007];
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
 
 
int main()
{
	int T, t, i, val, back;
	char c;
 
//	freopen("input.txt", "r", stdin);
	
	T = FAST_IO();
 
	for (t = 1; t <= T; t++)
	{
		back = 0;
 
		N = FAST_IO();
 
		printf("Case %d:\n", t);
 
		for (i = 0; i < N; i++)
		{
			c = gc();
 
			switch (c)
			{
			case 'A':
				val = FAST_IO();
				if (back == 0)
					A[back++] = val;
				else
				{
					A[back] = max(val, A[back - 1]);
					back++;
				}
				break;
			case 'Q':
				if (back == 0)
					printf("Empty\n");
				else
					printf("%d\n", A[back - 1]);
				gc();
				break;
			case 'R':
				if (back)
					back--;			
				gc();
				break;
			}
		}
 
	}
 
	return 0;
} 
