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
#include <queue>
#include <vector>
 
using namespace std;
 
priority_queue<int> Q;
vector< pair<int, int> > A;
 
int main()
{
	int N, i;
	pair<int, int> temp;
	long long sum=0, tt;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &N);
 
	A.push_back(make_pair(0,0));
	for(i=0; i<N; i++)
	{
		scanf("%d %d", &temp.first, &temp.second);
		sum+=temp.first;
 
		A.push_back(temp);
	}
 
	
	sum-=(A[1].first-A[1].second);
 
	for(i=2; i<=N; i++)
	{
		Q.push(A[i].first-A[i].second);
 
		if(i%2)
		{
			tt=Q.top();
			sum-=Q.top();
			Q.pop();
		}
	}
 
	printf("%lld\n", sum);
	
	return 0;
} 
