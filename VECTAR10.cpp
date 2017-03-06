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
 
using namespace std;
 
int p[] = { 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288 };
int V = 524288;
int N;
 
inline bool init()
{
	scanf("%d", &N);
 
	return N != 0;
}
 
inline int solve(int N)
{
	int *ii;
 
	if (N == 1)
		return 1;
	
	if (N >= V)
		ii = &V;
 
	else
	{
		ii = upper_bound(p, p + 19, N);
		ii--;
	}
 
	if (*ii == N)
		return N;
 
	return (N - *ii) * 2;
}
 
int main()
{
	while (init())
		printf("%d\n", solve(N));
 
	return 0;
} 
