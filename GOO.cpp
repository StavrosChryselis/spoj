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
#include <math.h>
 
using namespace std;
 
int N;
unsigned long long sum, aces;
 
int main()
{
	int T;
 
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%d", &N);
 
		sum = pow(2, N - 1);
		aces = sum + (sum / 2) * (N - 1);
 
		printf("%llu %llu\n", sum, aces);
	}
 
	return 0;
} 
