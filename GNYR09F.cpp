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
#include <iostream>
 
using namespace std;
 
unsigned long long DP[110][110][2];
int N, K;
 
int main()
{
	int i, j, k, T, N, K;
	//freopen("input.txt","r",stdin);
 
	DP[1][0][0] = 1;
	DP[1][0][1] = 1;
 
	for(i=2; i<=109; i++)
		for(j=0; j<=109; j++)
		{
			DP[i][j][0] = DP[i-1][j][1] + DP[i-1][j][0];
			if(j > 0)
				DP[i][j][1] = DP[i-1][j-1][1];
			DP[i][j][1]+=DP[i-1][j][0];
		}
 
	scanf("%d", &T);
 
	for(i=1; i<=T; i++)
	{
		scanf("%d %d %d", &i, &N, &K);
		cout<<i<<" "<<DP[N][K][0] + DP[N][K][1]<<endl;
	}
	return 0;
} 
