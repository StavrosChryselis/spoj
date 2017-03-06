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
#include <map>
#include <vector>
#define max(a, b) (a>b)?a:b;
 
using namespace std;
 
map<int, unsigned long long> DP;
vector<int> A;
int N;
 
unsigned long long solve(int curr)
{
	if(DP.find(curr)!=DP.end())
		return DP[curr];
 
	DP[curr]=max(curr, solve(curr/2)+solve(curr/3)+solve(curr/4));
 
	return DP[curr];
}
 
int main()
{
	int i;
	int num;
 
	//freopen("input.txt","r",stdin);
 
 
	while(scanf("%d", &num)!=EOF)
	{
		A.push_back(num);
		N=max(N, num);
	}
 
	DP[0]=0;
	DP[1]=1;
	DP[2]=2;
	DP[3]=3;
 
	for(i=0; i<A.size(); i++)
		printf("%lld\n", solve(A[i]));
 
	return 0;
} 
