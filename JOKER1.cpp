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
#include <algorithm>
 
#define MOD 1000000007
using namespace std;
 
int A[100];
int N;
 
inline void init()
{
	int i;
 
	scanf("%d", &N);
 
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
 
	sort(A, A + N);
}
 
inline long long solve()
{
	long long sum = 0;
	int i;
 
	sum = A[0];
 
	for (i = 1; i < N; i++)
	{
		A[i]-= i;
		sum *= A[i];
		sum %= MOD;
	}
 
	return sum;
}
 
int main()
{
	int T;
 
	//freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	while (T--)
	{
		init();
		printf("%lld\n", solve());
	}
 
	printf("KILL BATMAN\n");
 
	return 0;
} 
