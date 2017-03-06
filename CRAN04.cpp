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
#define gc() getchar_unlocked()
 
using namespace std;
 
long long count[1000010];
int N, K;
 
inline long long solve()
{
	int i;
	long long sum = 0, curr_sum = 0;
	char c;
 
	memset(count, 0, sizeof(count));
 
	scanf("%d %d\n", &N, &K);
 
	for(i=0; i<N; i++)
	{
		c = gc();
 
		if(c == '1')
			curr_sum++;
 
		if(curr_sum >= K)
			sum += count[curr_sum - K];
		count[curr_sum]++;
	}
 
	return sum + count[K];
}
 
int main()
{
	int T;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while(T--)
		printf("%lld\n", solve());
 
	return 0;
} 
