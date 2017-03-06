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
 
int N, M, K;
 
inline long long solve()
{
	vector<int> X, Y;
	int maxX = 0, maxY = 0;
	int i, x, y;
 
	scanf("%d %d %d", &N, &M, &K);
 
	if(K == 0)
		return N * M;
 
	X.push_back(0);
	Y.push_back(0);
	X.push_back(N + 1);
	Y.push_back(M + 1);
 
	for(i = 0; i < K; i++)
	{
		scanf("%d %d", &x, &y);
		X.push_back(x);
		Y.push_back(y);
	}
 
 
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
 
	for(i = 1; i < X.size(); i++)
	{
		if(X[i] - X[i - 1] - 1 > maxX)
			maxX = X[i] - X[i - 1] - 1;
		if(Y[i] - Y[i - 1] - 1 > maxY)
			maxY = Y[i] - Y[i - 1] - 1;
	}
 
	return maxX * maxY;
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
