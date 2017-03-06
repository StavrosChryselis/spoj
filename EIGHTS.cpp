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
 
int main()
{
	int T, i;
	unsigned long long res, num;
	
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%lld", &num);
		printf("%lld\n", 192+(num-1)*250);
	}
	
 
	return 0;
} 
