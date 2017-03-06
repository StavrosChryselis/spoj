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
 
using namespace std;
 
float N, M, K;
 
inline int solve()
{
	float minX, minY;
	
	scanf("%f %f %f", &N, &M, &K);
 
	minX = ceil((N - K) / (K + 1));
	minY = ceil((M - K) / (K + 1));
 
	return minX * minY;
}
 
int main()
{
	int T;
 
	scanf("%d", &T);
 
	while(T--)
		printf("%d\n", solve());
 
	return 0;
} 
