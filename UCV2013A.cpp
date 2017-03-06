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
#include <limits.h>
#include <math.h>
 
int main()
{
	long long N, L;
	int i;
	long long res;
	long long s;
	//freopen("input.txt","r",stdin);
	scanf("%lld %lld", &N, &L);
 
	while(N!=0 && L!=0)
	{
		res=s=N;
		for(i=0; i<L-1; i++)
		{
			s=(s*N)%1000000007;
			res+=s;
			res%=1000000007;
		}
		printf("%lld\n", res);
		scanf("%lld %lld", &N, &L);
	}
 
	return 0;
} 
