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
#include <unordered_map>
 
using namespace std;
 
unordered_map< unsigned long long, bool > found;
 
int main()
{
	unsigned long long N;
	scanf("%llu", &N);
 
	while(N>1)
	{
		if(found.find(N)!=found.end())
		{
			printf("NIE\n");
			return 0;
		}
		found[N]=1;
		if(N%2==0)
			N/=2;
		else
			N=3*N+3;
	}
 
	printf("TAK\n");
	return 0;
} 
