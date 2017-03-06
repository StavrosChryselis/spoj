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
#include <cmath>
 
using namespace std;
 
int N;
 
inline int solvex()
{
	int ans;
 
	if (N == 0)
		return 0;
 
	if (N == 1)
		return 1;
 
	ans = ceil(N / 2.0);
 
	if (ans % 2 == 0)
		ans = -ans;
 
	return ans;
}
 
inline int solvey()
{
	int ans;
 
	if (N == 0 || N == 1)
		return 0;
 
	ans = ceil((N - 1) / 4.0) * 2;
 
	if (N % 4 == 0 || N % 4 == 1)
		ans = -ans;
 
	return ans;
}
 
int main()
{
	int T;
 
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%d", &N);
		printf("%d %d\n", solvex(), solvey());
	}
 
	return 0;
} 
