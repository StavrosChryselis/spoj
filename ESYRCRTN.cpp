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
 
int A[6] = { 0, 1, 4, 6, 5, 2};
 
int main()
{
	int T;
	long long num;
 
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%lld", &num);
		printf("%d\n", A[num % 6]);
	}
 
	return 0;
} 
