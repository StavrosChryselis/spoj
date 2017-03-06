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
 
#define MOD 1000000007
using namespace std;
 
int DP[1000007];
 
inline void init()
{
	int i;
 
	DP[2] = DP[3] = 1;
 
	for (i = 4; i <= 1000000; i++)
	{
		DP[i] = DP[i - 3] + DP[i - 2];
		if (DP[i] >= MOD)
			DP[i] -= MOD;
	}
}
 
int main()
{
	int num, T;
 
	init();
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%d", &num);
		printf("%d\n", DP[num]);
	}
 
	return 0;
} 
