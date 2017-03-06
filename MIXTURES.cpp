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
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
#define min(a, b) ((a<b)?a:b)
 
int N;
int MIX[101][101];
int COL[101][101];
 
void dp()
{
	int i, j, k, l;
	int MIX[101][101];
	int COL[101][101];
 
	for(i=1; i<=N; i++)
	{
		for(j=1; j<=N; j++)
		{
			MIX[i][j]=INT_MAX;
			COL[i][j]=0;
		}
		scanf("%d", &COL[i][i]);
	}
 
	for(i=1; i<=N-1; i++)
	{
		MIX[i][i]=0;
		MIX[i][i+1]=COL[i][i]*COL[i+1][i+1];
		COL[i][i+1]=(COL[i][i]+COL[i+1][i+1])%100;
	}
 
	MIX[N][N]=0;
 
	for(k=3; k<=N; k++)
	{
		for(i=1; i+k-1<=N; i++)
		{
			j=i+k-1;
 
			for(l=i; l<j; l++)
			{
				if(MIX[i][l] + MIX[l+1][j] + COL[i][l]*COL[l+1][j] <  MIX[i][j])
				{
					MIX[i][j]=MIX[i][l] + MIX[l+1][j] + COL[i][l]*COL[l+1][j];
					COL[i][j]=(COL[i][l]+COL[l+1][j])%100;
				}
			}
		}
	}
 
		printf("%d\n", MIX[1][N]);
}
 
int main()
{
 
	while(scanf("%d",&N)>0) 
		dp();
 
	return 0;
} 
