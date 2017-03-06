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
 
int SUM[100007];
int N;
 
inline void init()
{
	int num, i;
	
	scanf("%d", &N);
	
	for(i = 1; i<=N; i++)
	{
		scanf("%d", &num);
		SUM[i] = SUM[i - 1] + num;
	}
}
 
int main()
{
	int A, B, Q;
	
	init();
	
	scanf("%d", &Q);
	
	while(Q--)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", SUM[B] - SUM[A - 1]);
	}
	
	return 0;
} 
