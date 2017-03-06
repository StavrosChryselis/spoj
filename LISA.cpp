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
#include <algorithm>
#include <limits.h>
#define gc() getchar()
 
using namespace std;
 
int NUMBERS[100];
bool OPERATIONS[100];
unsigned long long DPMAX[100][100];
unsigned long long DPMIN[100][100];
int N;
 
void init()
{
	char c;
	int temp;
	int i=0, j=0;
 
	c=gc();
	while(c!='\n' && c!=EOF)
	{
		if(isdigit(c))
		{
			ungetc(c, stdin);
			scanf("%d", &temp);
			NUMBERS[i++]=temp;
		}
		else
		{
			switch(c)
			{
				case '+':
					OPERATIONS[j++]=0;
					break;
				case '*':
					OPERATIONS[j++]=1;
					break;
			}
		}
		c=gc();
	}
	N=i;
}
 
void solve()
{
	int i, j, k, L;
 
	for(i=0; i<N; i++)
		DPMAX[i][i] = DPMIN[i][i] = NUMBERS[i];
	for(i=0; i<N-1; i++)
		DPMAX[i][i+1] = DPMIN[i][i+1] = (OPERATIONS[i]==0)?NUMBERS[i] + NUMBERS[i+1]:NUMBERS[i]*NUMBERS[i+1];
 
	for(L=3; L<=N; L++)
		for(i=0; i+L-1<N; i++)
		{
			j = i+L-1;
			DPMAX[i][j]=0;
			DPMIN[i][j]=LLONG_MAX;
			for(k=i; k<j; k++)
			{
				if(OPERATIONS[k]==0)
				{
					DPMAX[i][j]=max(DPMAX[i][j], DPMAX[i][k] + DPMAX[k+1][j]);
					DPMIN[i][j]=min(DPMIN[i][j], DPMIN[i][k] + DPMIN[k+1][j]);
				}
				else
				{
					DPMAX[i][j]=max(DPMAX[i][j], DPMAX[i][k] * DPMAX[k+1][j]);
					DPMIN[i][j]=min(DPMIN[i][j], DPMIN[i][k] * DPMIN[k+1][j]);
				}
			}
		}
}
int main()
{
	int T;
 
	//freopen("input.txt","r",stdin);
	scanf("%d\n", &T);
 
	while(T--)
	{
		init();
		solve();
		printf("%llu %llu\n", DPMAX[0][N-1], DPMIN[0][N-1]);
	}
	return 0;
} 
