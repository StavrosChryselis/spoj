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
#include <algorithm>
#define gc() getchar_unlocked()
 
using namespace std;
int DP[6107][6107];
char str[6107];
int N;
 
void init()
{
	int i = 0;
	char c;
 
	c=gc();
	while(isspace(c))
		c=gc();
 
	while(!isspace(c) && c!=EOF)
	{
		str[i++] = c;
		c = gc();
	}
 
	N = i;
}
 
int main()
{
	int T, i, j, L;
 
	//freopen("input.txt","r",stdin);
	scanf("%d", &T);
 
	while(T--)
	{
		init();
 
		for(i=0; i<N; i++)
			DP[i][i] = 0;
 
		for(L = 2; L<=N; L++)
			for(i=0; i + L - 1 < N; i++)
			{
				j = i + L - 1;
				if(str[i] != str[j])
					DP[i][j] = 1 + min(DP[i+1][j], DP[i][j-1]);
				else
					DP[i][j] = DP[i+1][j-1];
			}
 
		printf("%d\n", DP[0][N-1]);
	}
 
	return 0;
} 
