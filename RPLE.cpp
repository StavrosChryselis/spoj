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
#include <string.h>
 
using namespace std;
 
bool IN[1007], OUT[1007];
int N, E;
 
inline bool solve()
{
	bool ans = 1;
 
	memset(IN, 0, sizeof(IN));
	memset(OUT, 0, sizeof(OUT));
 
	int i, f, s;
 
	scanf("%d %d", &N, &E);
 
	for (i = 0; i < E; i++)
	{
		scanf("%d %d", &f, &s);
		OUT[f] = 1;
		IN[s] = 1;
 
		if ((OUT[f] && IN[f]) || (OUT[s] && IN[s]))
			ans = 0;
	}
 
	return ans;
}
 
int main()
{
	int T, i;
 
//	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
 
	for (i = 1; i <= T; i++)
	{
		if (solve())
			printf("Scenario #%d: spying\n", i);
		else
			printf("Scenario #%d: spied\n", i);
	}
 
	return 0;
} 
