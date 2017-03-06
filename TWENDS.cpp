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
 
int N;
int DP[10000][10000];
int A[10000];
int sum;
 
inline bool max_pos(int left, int right)
{
	if(left>=right)
		return 0;
	return 1;
}
 
 
bool init()
{
	int i;
 
	scanf("%d", &N);
	sum=0;
	if(N==0)
		return 0;
 
	for(i=1; i<=N; i++)
	{
		scanf("%d", &A[i]);
		sum+=A[i];
	}
 
	return 1;
}
 
int main()
{
	int i, j, L, t;
	int left, right;
 
	//freopen("input.txt","r",stdin);
 
	for(t=1; init(); t++)
	{
		for(i=2; i<=N; i++)
			DP[i-1][i]=max(A[i], A[i-1]);
 
		for(L=4; L<=N; L+=2)
		{
			for(i=1; i<=N; i++)
			{
				j=i+L-1;
 
				left=A[i];
 
				if(max_pos(A[i+1], A[j])==0)
					left+=DP[i+2][j];
				else
					left+=DP[i+1][j-1];
 
				right=A[j];
 
				if(max_pos(A[i], A[j-1])==0)
					right+=DP[i+1][j-1];
				else
					right+=DP[i][j-2];
 
				DP[i][j]=max(left, right);
			}
		}
 
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", t, DP[1][N]-(sum-DP[1][N]));
	}
 
	return 0;
} 
