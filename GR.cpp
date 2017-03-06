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
 
using namespace std;
 
int A[30][30];
int N, T;
 
inline void init()
{
	int i, j, c;
 
	scanf("%d %d", &N, &T);
 
	T %= 4;
	c = 1;
 
		switch (T)
		{
		case 0:
			for (i = 1; i <= N; i++)
				for (j = 1; j <= N; j++, c++)
					A[i][j] = c;
			break;
		case 1:
			for (j = N; j >= 1; j--)
				for (i = 1; i <= N; i++, c++)
					A[i][j] = c;
			break;
		case 2:
			for (i = N; i >= 1; i--)
				for (j = N; j >= 1; j--, c++)
					A[i][j] = c;
			break;
		case 3:
			for (j = 1; j <= N; j++)
				for (i = N; i >= 1; i--, c++)
					A[i][j] = c;
			break;
		}
}
 
inline void solve()
{
	int i, j, Ameen = 0, Shafeek = 0, Atef = 0, Sameh = 0;
 
	for (i = 1; i <= N; i++)
	{
		Ameen += A[1][i];
		Shafeek += A[i][N];
		Atef += A[N][i];
		Sameh += A[i][1];
	}
 
	if (Ameen > Shafeek && Ameen > Atef && Ameen > Sameh)
		printf("Ameen\n");
 
	else if (Shafeek > Atef && Shafeek > Sameh)
		printf("Shafeek\n");
 
	else if (Atef > Sameh)
		printf("Atef\n");
 
	else
		printf("Sameh\n");
 
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}
 
int main()
{
	init();
	solve();
 
	return 0;
} 
