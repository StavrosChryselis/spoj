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
 
int G[207][207];
int N;
 
void init()
{
	int i, j;
 
	scanf("%d", &N);
 
	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
			scanf("%d", &G[i][j]);
}
 
inline int check(int A, int B)
{
	int i;
 
	for(i=1; i<=N; i++)
		if(i!=A && i!=B && G[A][i] + G[i][B] == G[A][B])
			return 0;
 
	return 1;
}
 
int main()
{
	int T;
	int i, j;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while(T--)
	{
		init();
 
		for(i=1; i<=N; i++)
			for(j = i+1; j<=N; j++)
				if(check(i, j))
					printf("%d %d\n", i, j);
		printf("\n");
	}
 
	return 0;
} 
