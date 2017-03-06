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
 
inline long long solve(int num)
{
	long long ans = 0;
	int i;
 
	for(i=1; i<=num; i++)
		ans += pow( (float)(num - i) + 1, 2);
 
	return ans;
}
 
int main()
{
	int N;
 
	scanf("%d", &N);
 
	while(N!=0)
	{
		printf("%lld\n", solve(N));
		scanf("%d", &N);
	}
 
	return 0;
} 
