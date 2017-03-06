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
 
int N;
int DP[1000007];
 
inline bool check(int pos)
{
	int i;
 
	for (i = 1; i * i <= pos; i++)
		if (!DP[pos - i * i])
			return 1;
 
	return 0;
}
 
inline void pre()
{
	int i;
 
	for (i = 1; i <= 1000000; i++)
		DP[i] = check(i);
}
 
int main()
{
	int T;
 
	pre();
 
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%d", &N);
		if (DP[N])
			printf("Win\n");
		else
			printf("Lose\n");
	}
 
	return 0;
} 
