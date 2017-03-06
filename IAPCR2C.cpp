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
 
int N, M;
int marked[100007];
 
inline void init()
{
	scanf("%d %d", &N, &M);
 
	memset(marked, 0, sizeof(marked));
	marked[0] = 1;
	marked[N + 1] = 1;
}
 
inline int solve()
{
	int sum = 0, num, i;
 
	for (i = 0; i < M; i++)
	{
		scanf("%d", &num);
		if (!marked[num])
			sum++;
		if (!marked[num - 1])
			sum++;
		if (!marked[num + 1])
			sum++;
 
		marked[num] = marked[num - 1] = marked[num + 1] = 1;
	}
 
	return sum;
}
 
int main()
{
	int T, i;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	for (i = 1; i <= T; i++)
	{
		init();
		printf("Case %d: %d\n", i, solve());
	}
 
	return 0;
} 
