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
#include <set>
 
using namespace std;
 
int A[1000007];
int N;
 
inline void init()
{
	int i;
 
	scanf("%d", &N);
 
	for (i = 1; i <= N; i++)
		scanf("%d", &A[i]);
}
 
inline int solve()
{
	multiset< int > V;
	int i;
	multiset< int >::iterator ii;
 
	V.insert(A[1] - 1);
 
	for (i = 2; i <= N; i++)
		if (A[i] >= i)
		{
			A[i] -= i;
			ii = V.insert(A[i]);
 
			if (next(ii) != V.end())
				V.erase(next(ii));
		}
 
	return V.size();
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
	
	init();
	printf("%d\n", N - solve());
 
	return 0;
} 
