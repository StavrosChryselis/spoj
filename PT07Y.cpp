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
#include <set>
#include <algorithm>
 
using namespace std;
 
set<int> A;
 
int main()
{
	int i, n, m;
	int v1, v2;
 
	scanf("%d %d", &n, &m);
 
	if(n-m!=1)
	{
		printf("NO\n");
		return 0;
	}
 
	for(i=0; i<m; i++)
	{
		scanf("%d %d", &v1, &v2);
		A.insert(v1);
		if(A.find(v2)!=A.end())
		{
			printf("NO\n");
			return 0;
		}
		A.insert(v2);
	}
 
	printf("YES\n");
 
	return 0;
} 
