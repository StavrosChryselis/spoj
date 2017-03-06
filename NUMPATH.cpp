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
 
int R, C;
 
inline long long factorial(int num)
{
	long long ans = 1;
	int i;
 
	if (num == 0)
		return 1;
 
	for (i = 2; i <= num; i++)
		ans *= i;
 
	return ans;
}
 
inline long long solve()
{
	if (R == 1 && C == 1)
		return 1;
 
	return factorial(R + C - 2) / (factorial(R - 1) * factorial(C - 1));
}
 
int main()
{
	int T;
 
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%d %d", &R, &C);
		printf("%lld\n", solve());
	}
 
	return 0;
} 
