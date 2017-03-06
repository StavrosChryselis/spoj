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
#include <algorithm>
 
using namespace std;
 
vector<bool> Result;
int N, K, L, maxi;
vector<int> NUMS;
 
inline bool check(int num)
{
	if(num-1>=0 && Result[num-1]==0)
		return 1;
	else if(num-K>=0 && Result[num-K]==0)
		return 1;
	else if(num-L>=0 && Result[num-L]==0)
		return 1;
 
	return 0;
}
 
void solve()
{
	int i;
	Result.resize(maxi+1);
 
	Result[0]=0;
 
	for(i=1; i<=maxi; i++)
		Result[i]=check(i);
}
 
int main()
{
	int i;
 
//	freopen("coins.in","r",stdin);
//	freopen("coins.out","w",stdout);
 
	scanf("%d %d %d", &K, &L, &N);
	NUMS.resize(N);
	for(i=0; i<N; i++)
		scanf("%d", &NUMS[i]);
 
	sort(NUMS.begin(), NUMS.end());
	maxi=NUMS[N-1];
	solve();
 
	for(i=0; i<NUMS.size(); i++)
	{
		if(Result[NUMS[i]])
			printf("A");
		else
			printf("B");
	}
	printf("\n");
	return 0;
} 
