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
#include <string.h>
 
using namespace std;
 
int sum;
int memo[100007];
 
inline void init()
{
	memset(memo, -1, sizeof(memo));
 
	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 0;
}
 
int F(int a)
{
 
	if (memo[a] != -1)
		return memo[a];
 
	int root = sqrt(a);
 
	if (root * root == a)
	{
		memo[a] = 2 * F(root);
		return memo[a];
	}
 
	for (int i = root; i > 1; i--)
		if (a % i == 0)
		{
			memo[a] = F(i) + F(a / i);
			return memo[a];
		}
	
	memo[a] = 0;
	return 0;
}
 
int main()
{
	int num;
 
	init();
	scanf("%d", &num);
	printf("%d\n", F(num));
 
	return 0;
} 
