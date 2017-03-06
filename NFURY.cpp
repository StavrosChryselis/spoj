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
#include <algorithm>
#include <vector>
#include <limits.h>
 
using namespace std;
 
vector<int> SQRS;
int DP[1007];
 
inline void precalc()
{
	int i, j;
 
	DP[0] = 0;
 
	for (i = 1; i * i <= 1000; i++)
		SQRS.push_back(i*i);
 
	for (i = 1; i <= 1000; i++)
	{
		DP[i] = INT_MAX;
 
		for (j = 0; j < SQRS.size() && SQRS[j] <= i; j++)
			DP[i] = min(DP[i], DP[i - SQRS[j]] + 1);
	}
}
 
int main()
{
	int T, num;
 
	//freopen("input.txt", "r", stdin);
 
	precalc();
 
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%d", &num);
		printf("%d\n", DP[num]);
	}
 
	return 0;
} 
