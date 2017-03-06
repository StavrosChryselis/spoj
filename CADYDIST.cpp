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
#include <functional>
 
using namespace std;
 
int N;
long long A[100007], B[100007];
 
inline bool init()
{
	int i;
	
	scanf("%d", &N);
	
	if(!N)
		return 0;
		
	for(i = 0; i<N; i++)
		scanf("%lld", &A[i]);
		
	for(i = 0; i<N; i++)
		scanf("%lld", &B[i]);
		
	sort(A, A + N);
	sort(B, B + N, greater<long long>());
	
	return 1;
}
 
inline long long solve()
{
	long long ans = 0;
	
	for(int i = 0; i<N; i++)
		ans += A[i] * B[i];
		
	return ans;
}
 
int main()
{
	while(init())
		printf("%lld\n", solve());
	
	return 0;
} 
