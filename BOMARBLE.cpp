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

int A[10001];
 
int main()
{
	int i, N, diff;
 
	//freopen("input.txt","r",stdin);
 
	A[1] = 5;
	diff = 7;
 
	for(i=2; i<=10000; i++)
	{
		A[i] = A[i-1] + diff;
		diff += 3;
	}
 
	scanf("%d", &N);
 
	while(N)
	{
		printf("%d\n", A[N]);
		scanf("%d", &N);
	}
 
	return 0;
} 
