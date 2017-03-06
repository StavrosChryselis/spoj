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

#include <iostream>
using namespace std;
 
int main() 
{
	int T, N, M, i;
	
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d %d", &N, &M);
		printf("%d\n", (N - 1) * M + N * (M - 1));
	}
	return 0;
} 
