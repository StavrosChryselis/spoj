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
 
int modular_pow(int base, int exponent, int modulus)
{
	int res=1;
	base = base%modulus;
	while(exponent > 0)
	{
		if(exponent % 2)
			res = (res*base) % modulus;
		exponent >>= 1;
		base = (base*base) % modulus;
	}
 
	return res;
}
 
int main()
{
	int N, i, b, e;
 
	//freopen("input.txt","r",stdin);
	scanf("%d", &N);
 
	for(i=0; i<N; i++)
	{
		scanf("%d %d", &b, &e);
		printf("%d\n", modular_pow(b, e, 10));
	}
 
	return 0;
} 
