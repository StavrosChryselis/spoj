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
#include <vector>
 
using namespace std;
 
int N;
vector<int> A;
long long sum;
 
inline bool init()
{
	int i, num;
 
	sum = 0;
	A.clear();
 
	scanf("%d", &N);
 
	if(N == -1)
		return 0;
 
	for(i=0; i<N; i++)
	{
		scanf("%d", &num);
		A.push_back(num);
		sum += num;
	}
 
	return 1;
}
 
inline long long solve()
{
	int i;
	long long ans = 0, avg;
 
	if(sum % N != 0)
		return -1;
 
	avg = sum / N;
 
	for(i=0; i<N; i++)
		if(A[i] < avg)
			ans += avg - A[i];
 
	return ans;
}
 
int main()
{
	
	//freopen("input.txt","r",stdin);
 
	while(init())
		printf("%lld\n", solve());
 
	return 0;
} 
